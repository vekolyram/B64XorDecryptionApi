using System.Text;
using System;
using System.Collections.Generic;
using System.Text;

namespace B64XorDecryptionApi
{
public static class DataDecoder
    {
        // 从二进制中提取的固定长度查找表 (75个元素)
        private static int[] SALT_LENGTH_TABLE = {
        47, 53, 73, 55, 61, 103, 47, 103, 33, 45,
        73, 37, 97, 71, 39,  71, 31,  61, 83, 101,
        53, 97, 79, 75, 37,  31, 33,  69, 43,  63,
        39, 43, 79, 55, 49,  73, 83,  67, 59,  69,
       103, 39, 47, 37, 41,  71, 89,  55, 49,  45,
        33, 45, 41, 71, 89,  55, 49,  45, 33,  45,
        69, 49, 43, 53, 59,  31, 59, 101, 61,  41,
        79, 75, 83, 89, 75
    };
        public static void setSaltLengthTable(int[] newTable)
        {
            if (newTable.Length != 75)
                throw new ArgumentException("Salt length table must have exactly 75 elements.");
            SALT_LENGTH_TABLE = newTable;
        }
        public class DecodeResult
        {
            public int TableIndex { get; set; }
            public int KeyLength { get; set; }
            public int DataLength { get; set; }
            public long ActionId { get; set; }
            public string Key { get; set; }
            public string Plaintext { get; set; }
        }
        public static DecodeResult Decode(string encoded)
        {
            int tableIndex = int.Parse(encoded.Substring(0, 2));
            int dataLength = int.Parse(encoded.Substring(2, 6));
            string body = encoded.Substring(8);
            int keyLength = SALT_LENGTH_TABLE[tableIndex];
            string b64ActionId = body.Substring(0, 4);
            string keyStr = body.Substring(4, keyLength);
            string b64Cipher = body.Substring(4 + keyLength);
            byte[] actionIdBytes = Convert.FromBase64String(b64ActionId);
            byte[] keyBytes = Encoding.ASCII.GetBytes(keyStr);
            byte[] cipherBytes = Convert.FromBase64String(b64Cipher);
            byte[] plaintextBytes = new byte[cipherBytes.Length];
            for (int i = 0; i < cipherBytes.Length; i++)
            {
                plaintextBytes[i] = (byte)(cipherBytes[i] ^ keyBytes[i % keyLength]);
            }
            string plaintext = Encoding.UTF8.GetString(plaintextBytes);
            int actionIdHigh = actionIdBytes[0] ^ keyBytes[0];
            int actionIdMid = actionIdBytes[1] ^ keyBytes[1 % keyLength];
            int actionIdLow = actionIdBytes[2] ^ keyBytes[2 % keyLength];
            long actionId = (actionIdHigh << 16) | (actionIdMid << 8) | actionIdLow;
            return new DecodeResult
            {
                TableIndex = tableIndex,
                KeyLength = keyLength,
                DataLength = dataLength,
                ActionId = actionId,
                Key = keyStr,
                Plaintext = plaintext
            };
        }
    }
}