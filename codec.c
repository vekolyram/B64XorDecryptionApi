#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#include <windows.h>
#include <psapi.h>
#else
#define EXPORT
#endif

// ==================== 调用者校验 ====================
static int verify_caller(void) {
    return 1;
}

// ==================== Base64 编码/解码 ====================
static const char B64_CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static const unsigned char B64_DECODE[256] = {
    ['A']=0,  ['B']=1,  ['C']=2,  ['D']=3,  ['E']=4,  ['F']=5,  ['G']=6,  ['H']=7,
    ['I']=8,  ['J']=9,  ['K']=10, ['L']=11, ['M']=12, ['N']=13, ['O']=14, ['P']=15,
    ['Q']=16, ['R']=17, ['S']=18, ['T']=19, ['U']=20, ['V']=21, ['W']=22, ['X']=23,
    ['Y']=24, ['Z']=25, ['a']=26, ['b']=27, ['c']=28, ['d']=29, ['e']=30, ['f']=31,
    ['g']=32, ['h']=33, ['i']=34, ['j']=35, ['k']=36, ['l']=37, ['m']=38, ['n']=39,
    ['o']=40, ['p']=41, ['q']=42, ['r']=43, ['s']=44, ['t']=45, ['u']=46, ['v']=47,
    ['w']=48, ['x']=49, ['y']=50, ['z']=51, ['0']=52, ['1']=53, ['2']=54, ['3']=55,
    ['4']=56, ['5']=57, ['6']=58, ['7']=59, ['8']=60, ['9']=61, ['+']=62, ['/']=63,
};

static int base64_encode(const unsigned char *input, int input_len, char *output) {
    int out_len = 0;
    for (int i = 0; i < input_len; i += 3) {
        int remaining = input_len - i;
        unsigned int block = (unsigned int)input[i] << 16;
        if (remaining > 1) block |= (unsigned int)input[i + 1] << 8;
        if (remaining > 2) block |= (unsigned int)input[i + 2];

        output[out_len++] = B64_CHARS[(block >> 18) & 0x3F];
        output[out_len++] = B64_CHARS[(block >> 12) & 0x3F];
        output[out_len++] = (remaining > 1) ? B64_CHARS[(block >> 6) & 0x3F] : '=';
        output[out_len++] = (remaining > 2) ? B64_CHARS[block & 0x3F] : '=';
    }
    output[out_len] = '\0';
    return out_len;
}

static int base64_decode(const char *input, int input_len, unsigned char *output) {
    int out_len = 0;
    int len = input_len;
    while (len > 0 && input[len - 1] == '=') len--;

    for (int i = 0; i < len; ) {
        unsigned int block = 0;
        int n = 0;
        for (int j = 0; j < 4 && i < len; j++, i++) {
            block = (block << 6) | B64_DECODE[(unsigned char)input[i]];
            n++;
        }
        for (int j = n; j < 4; j++)
            block <<= 6;

        if (n >= 2) output[out_len++] = (block >> 16) & 0xFF;
        if (n >= 3) output[out_len++] = (block >> 8)  & 0xFF;
        if (n >= 4) output[out_len++] =  block        & 0xFF;
    }
    return out_len;
}

// ==================== 密钥长度查找表 (75个) ====================
static const int SALT_LENGTH_TABLE[75] = {
     47,  53,  73,  55,  61, 103,  47, 103,  33,  45,
     73,  37,  97,  71,  39,  71,  31,  61,  83, 101,
     53,  97,  79,  75,  37,  31,  33,  69,  43,  63,
     39,  43,  79,  55,  49,  73,  83,  67,  59,  69,
    103,  39,  47,  37,  41,  71,  89,  55,  49,  45,
     33,  45,  69,  49,  43,  53,  59,  31,  59, 101,
     61,  41,  79,  75,  83,  89,  75,  67,  41,  89,
     63, 101,  67,  63,  97,
};

static int g_initialized = 0;

static void ensure_init(void) {
    if (!g_initialized) {
        srand((unsigned int)time(NULL));
        g_initialized = 1;
    }
}

// ==================== 编码 (加密) ====================
// 导出名混淆: _xR7qM2vP (原 codec_encode)
EXPORT int _xR7qM2vP(const char *plaintext, int action_id, char *output, int output_buf_size) {
    if (!verify_caller()) return -1;
    ensure_init();

    int data_length = (int)strlen(plaintext);
    if (data_length <= 0) return -1;

    int table_index = rand() % 75;
    int key_length = SALT_LENGTH_TABLE[table_index];

    char *key = (char *)malloc(key_length + 1);
    if (!key) return -1;
    for (int i = 0; i < key_length; i++) {
        key[i] = B64_CHARS[rand() % 64];
    }
    key[key_length] = '\0';

    unsigned char *cipher = (unsigned char *)malloc(data_length);
    if (!cipher) { free(key); return -1; }
    for (int i = 0; i < data_length; i++) {
        cipher[i] = (unsigned char)plaintext[i] ^ (unsigned char)key[i % key_length];
    }

    int aid = action_id & 0xFFFFFF;
    unsigned char action_bytes[3];
    action_bytes[0] = (unsigned char)((aid >> 16) & 0xFF) ^ (unsigned char)key[0];
    action_bytes[1] = (unsigned char)((aid >> 8)  & 0xFF) ^ (unsigned char)key[1 % key_length];
    action_bytes[2] = (unsigned char)( aid        & 0xFF) ^ (unsigned char)key[2 % key_length];

    char b64_action[8] = {0};
    base64_encode(action_bytes, 3, b64_action);
    b64_action[4] = '\0';

    int b64_cipher_max = ((data_length + 2) / 3) * 4 + 4;
    char *b64_cipher = (char *)malloc(b64_cipher_max);
    if (!b64_cipher) { free(key); free(cipher); return -1; }
    int b64_cipher_len = base64_encode(cipher, data_length, b64_cipher);

    int total_len = 8 + 4 + key_length + b64_cipher_len;
    if (total_len + 1 > output_buf_size) {
        free(key); free(cipher); free(b64_cipher);
        return -1;
    }

    int pos = 0;
    pos += sprintf(output + pos, "%02d%06d", table_index, data_length);
    memcpy(output + pos, b64_action, 4);  pos += 4;
    memcpy(output + pos, key, key_length); pos += key_length;
    memcpy(output + pos, b64_cipher, b64_cipher_len); pos += b64_cipher_len;
    output[pos] = '\0';

    free(key);
    free(cipher);
    free(b64_cipher);
    return pos;
}

// ==================== 解码 (解密) ====================
// 导出名混淆: _kW3nJ9tF (原 codec_decode)
EXPORT int _kW3nJ9tF(const char *encoded, char *plaintext_out, int plaintext_buf_size, int *action_id_out) {
    if (!verify_caller()) return -1;

    int encoded_len = (int)strlen(encoded);
    if (encoded_len < 12) return -1;

    char idx_str[3] = { encoded[0], encoded[1], '\0' };
    char len_str[7] = { encoded[2], encoded[3], encoded[4], encoded[5], encoded[6], encoded[7], '\0' };

    int table_index = atoi(idx_str);
    int data_length = atoi(len_str);

    if (table_index < 0 || table_index >= 75) return -1;

    int key_length = SALT_LENGTH_TABLE[table_index];

    const char *body = encoded + 8;
    int body_len = encoded_len - 8;

    if (body_len < 4 + key_length) return -1;

    char b64_action[8] = {0};
    memcpy(b64_action, body, 4);
    b64_action[4] = '=';
    b64_action[5] = '=';
    b64_action[6] = '\0';
    unsigned char action_id_bytes[4] = {0};
    base64_decode(b64_action, 6, action_id_bytes);

    const char *key_str = body + 4;
    const unsigned char *key_bytes = (const unsigned char *)key_str;

    const char *b64_cipher = body + 4 + key_length;
    int b64_cipher_len = body_len - 4 - key_length;

    unsigned char *cipher_bytes = (unsigned char *)malloc(b64_cipher_len);
    if (!cipher_bytes) return -1;
    int cipher_len = base64_decode(b64_cipher, b64_cipher_len, cipher_bytes);

    int decrypt_len = cipher_len < data_length ? cipher_len : data_length;
    if (decrypt_len > plaintext_buf_size - 1) {
        free(cipher_bytes);
        return -1;
    }

    for (int i = 0; i < decrypt_len; i++) {
        plaintext_out[i] = (char)(cipher_bytes[i] ^ key_bytes[i % key_length]);
    }
    plaintext_out[decrypt_len] = '\0';

    int ah = action_id_bytes[0] ^ key_bytes[0];
    int am = action_id_bytes[1] ^ key_bytes[1 % key_length];
    int al = action_id_bytes[2] ^ key_bytes[2 % key_length];
    *action_id_out = (ah << 16) | (am << 8) | al;

    free(cipher_bytes);
    return decrypt_len;
}
