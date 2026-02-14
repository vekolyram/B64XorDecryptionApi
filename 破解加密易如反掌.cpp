//盐长表内存地址（动态调试得出的动态内存地址） 
qword_148F52418 = 0x00000000074A6000

//盐长表数组元素个数（0x4B = 75） 
dword_148F52420 = 4Bh

//字符集 
aAbcdefghijklmn_0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
 
//action回调函数
//其中 sub_144A4E2E0() 函数返回最终的 未被加密 的 原json字符串 
//=================================================================//
__int64 __fastcall sub_144A24D10(__int64 a1, __int64 a2, __int64 *a3, __int64 *a4)
{
  __int64 v8; // rax
  __int16 *v9; // rcx
  int v10; // eax
  int v11; // ecx
  __int64 v12; // rax
  __int64 v13; // r12
  __int64 *v14; // r13
  unsigned int v15; // esi
  unsigned int v16; // esi
  __int64 v17; // r12
  __int64 v18; // rax
  __int64 v19; // rsi
  int v20; // eax
  _DWORD *v21; // rcx
  __int64 result; // rax
  __int64 v23; // [rsp+40h] [rbp-39h] BYREF
  unsigned int v24; // [rsp+48h] [rbp-31h]
  int v25; // [rsp+4Ch] [rbp-2Dh] BYREF
  __int64 v26; // [rsp+50h] [rbp-29h] BYREF
  unsigned int v27; // [rsp+58h] [rbp-21h]
  int v28; // [rsp+5Ch] [rbp-1Dh] BYREF
  __int64 v29[2]; // [rsp+60h] [rbp-19h] BYREF
  char v30[16]; // [rsp+70h] [rbp-9h] BYREF
  char v31[16]; // [rsp+80h] [rbp+7h] BYREF
  int v32; // [rsp+90h] [rbp+17h]
  __int64 v33; // [rsp+98h] [rbp+1Fh] BYREF
  int v34; // [rsp+A0h] [rbp+27h]
  int v35; // [rsp+A4h] [rbp+2Bh]

  v8 = sub_1411CFD00(v29);
  if ( (unsigned __int8)sub_144A2A3F0(a1, v8) )
  {
    v32 = 0;
    sub_1411D0020(&v33, &Buf2);
    if ( *(_DWORD *)(a2 + 8) )
      v9 = *(__int16 **)a2;
    else
      v9 = &chText;
    v10 = sub_141217600(v9, "XActionEndOfTurn");
    v11 = v32;
    if ( !v10 )
      v11 = 1;
    v32 = v11;
    v12 = sub_1411D0020(v30, &Buf2);
    v13 = *a4;
    v14 = (__int64 *)v12;
    v23 = 0i64;
    v15 = *((_DWORD *)a4 + 2);
    v24 = v15;
    if ( v15 )
    {
      sub_1411B0CC0(32i64, 8i64, v15, 0i64, &v23, v15, &v25);
      sub_1449BE0F0(v23, v13, v15);
    }
    else
    {
      v25 = 0;
    }
    v16 = *((_DWORD *)a3 + 2);
    v17 = *a3;
    v26 = 0i64;
    v27 = v16;
    if ( v16 )
    {
      sub_1411B0CC0(40i64, 8i64, v16, 0i64, &v26, v16, &v28);
      sub_1449BDB70(v26, v17, v16);
    }
    else
    {
      v28 = 0;
    }
    v18 = sub_1411CFD00(v31);
    v19 = sub_144A4E2E0(a1, (__int64)v29, v18, (__int64)&v26, (__int64)&v23, v14);
    if ( &v33 != (__int64 *)v19 )
    {
      if ( v33 )
        sub_14123C760(v33);
      v33 = *(_QWORD *)v19;
      *(_QWORD *)v19 = 0i64;
      v34 = *(_DWORD *)(v19 + 8);
      v35 = *(_DWORD *)(v19 + 12);
      *(_QWORD *)(v19 + 8) = 0i64;
    }
    if ( v29[0] )
      sub_14123C760(v29[0]);
    v20 = *(_DWORD *)(a1 + 3056);
    if ( v20 == *(_DWORD *)(a1 + 3060) )
      v20 = sub_1411B1210(2072i64, a1 + 3048);
    *(_DWORD *)(a1 + 3056) = v20 + 1;
    v21 = (_DWORD *)(*(_QWORD *)(a1 + 3048) + 24i64 * v20);
    *v21 = v32;
    sub_1411CFD00(v21 + 2);
    if ( !*(_BYTE *)(a1 + 3064) )
    {
      *(_BYTE *)(a1 + 3064) = 1;
      sub_144A540A0(a1);
    }
    if ( v33 )
      sub_14123C760(v33);
  }
  if ( *(_QWORD *)a2 )
    sub_14123C760(*(_QWORD *)a2);
  sub_1449BE280(*a3, *((unsigned int *)a3 + 2));
  if ( *a3 )
    sub_14123C760(*a3);
  result = sub_1449BE5A0(*a4, *((unsigned int *)a4 + 2));
  if ( *a4 )
    return sub_14123C760(*a4);
  return result;
}
//=================================================================//

//生成最终的 {"a":"%s"} 格式的 json文本 （并发送？） 
//=================================================================//
void __fastcall sub_144A540A0(LARGE_INTEGER a1)
{
  __int16 *v2; // r8
  bool v3; // zf
  __int64 v4; // rcx
  _QWORD *v5; // rax
  __int64 *v6; // rax
  __int64 v7; // rcx
  __int64 v8; // rdx
  __int64 *v9; // r14
  __int64 v10; // rbx
  volatile signed __int32 *v11; // rbx
  volatile signed __int32 *v12; // rbx
  __int64 v13; // rdx
  __int64 (__fastcall ***v14)(); // rbx
  __int64 (__fastcall **v15)(); // rax
  _QWORD *v16; // rax
  __int64 *v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rdx
  __int64 v20; // rbx
  volatile signed __int32 *v21; // rbx
  volatile signed __int32 *v22; // rbx
  __int16 *v23; // [rsp+30h] [rbp-59h] BYREF
  int v24; // [rsp+38h] [rbp-51h]
  int v25; // [rsp+3Ch] [rbp-4Dh]
  __int64 v26; // [rsp+40h] [rbp-49h] BYREF
  __int64 v27; // [rsp+48h] [rbp-41h] BYREF
  __int64 v28; // [rsp+50h] [rbp-39h] BYREF
  __int64 v29; // [rsp+58h] [rbp-31h] BYREF
  __int16 *v30; // [rsp+60h] [rbp-29h] BYREF
  int v31; // [rsp+68h] [rbp-21h]
  int v32; // [rsp+6Ch] [rbp-1Dh]
  int v33; // [rsp+70h] [rbp-19h]
  __int64 v34[2]; // [rsp+78h] [rbp-11h] BYREF
  char v35[8]; // [rsp+88h] [rbp-1h] BYREF
  volatile signed __int32 *v36; // [rsp+90h] [rbp+7h]
  char v37[8]; // [rsp+98h] [rbp+Fh] BYREF
  volatile signed __int32 *v38; // [rsp+A0h] [rbp+17h]
  char v39[8]; // [rsp+A8h] [rbp+1Fh] BYREF
  volatile signed __int32 *v40; // [rsp+B0h] [rbp+27h]
  char v41[8]; // [rsp+B8h] [rbp+2Fh] BYREF
  volatile signed __int32 *v42; // [rsp+C0h] [rbp+37h]
  LARGE_INTEGER PerformanceCount; // [rsp+F0h] [rbp+67h] BYREF

  if ( !*(_DWORD *)(a1.QuadPart + 3056) || *(int *)(*(_QWORD *)(a1.QuadPart + 3416) + 2180i64) < 0 )
  {
    *(_BYTE *)(a1.QuadPart + 3064) = 0;
    return;
  }
  v33 = **(_DWORD **)(a1.QuadPart + 3048);
  sub_1411CFD00(v34);
  sub_144A52810(&v23, v34, *(unsigned int *)(*(_QWORD *)(a1.QuadPart + 3416) + 2180i64));
  v2 = &chText;
  if ( v24 )
    v2 = v23;
  sub_1411E77B0(&v30, L"{\"a\": \"%s\"}", v2);
  if ( v23 )
    sub_14123C760((__int64)v23);
  v23 = v30;
  v24 = v31;
  v25 = v32;
  QueryPerformanceCounter(&PerformanceCount);
  v3 = v33 == 2;
  v4 = *(_QWORD *)(a1.QuadPart + 3416);
  *(float *)(a1.QuadPart + 3408) = (double)(int)PerformanceCount.LowPart * *(double *)&qword_149046300 + 16777216.0;
  if ( v3 )
  {
    v5 = (_QWORD *)sub_144A48170(v4, v37);
    v6 = (__int64 *)(*(__int64 (__fastcall **)(_QWORD, char *, __int64, LONGLONG, __int16 **))(*(_QWORD *)*v5 + 72i64))(
                      *v5,
                      v35,
                      1i64,
                      a1.QuadPart + 1976,
                      &v23);
    v7 = v6[1];
    v8 = *v6;
    v26 = *v6;
    v27 = v7;
    if ( v7 )
    {
      _InterlockedIncrement((volatile signed __int32 *)(v7 + 8));
      v7 = v27;
    }
    v9 = (__int64 *)(a1.QuadPart + 3392);
    if ( (__int64 *)(a1.QuadPart + 3392) != &v26 )
    {
      *v9 = v8;
      v26 = 0i64;
      sub_14122C310(a1.QuadPart + 3400, &v27);
      v7 = v27;
    }
    if ( v7 )
    {
      if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 8), 0xFFFFFFFF) == 1 )
      {
        v10 = v27;
        (**(void (__fastcall ***)(__int64))v27)(v27);
        if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v10 + 12), 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v27 + 8i64))(v27, 1i64);
      }
    }
    v11 = v36;
    if ( v36 )
    {
      if ( _InterlockedExchangeAdd(v36 + 2, 0xFFFFFFFF) == 1 )
      {
        (**(void (__fastcall ***)(volatile signed __int32 *))v11)(v11);
        if ( _InterlockedExchangeAdd(v11 + 3, 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)v11 + 8i64))(v11, 1i64);
      }
    }
    v12 = v38;
    if ( v38 )
    {
      if ( _InterlockedExchangeAdd(v38 + 2, 0xFFFFFFFF) == 1 )
      {
        (**(void (__fastcall ***)(volatile signed __int32 *))v12)(v12);
        if ( _InterlockedExchangeAdd(v12 + 3, 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)v12 + 8i64))(v12, 1i64);
      }
    }
    v14 = (__int64 (__fastcall ***)())sub_1411D7AB0(40i64, *v9 + 24);
    if ( !v14 )
      goto LABEL_49;
    *v14 = &off_147C0F9C8;
    v14[2] = (__int64 (__fastcall **)())sub_1411D9AC0();
    v15 = &off_147D930A8;
  }
  else
  {
    v16 = (_QWORD *)sub_144A48170(v4, v41);
    v17 = (__int64 *)(*(__int64 (__fastcall **)(_QWORD, char *, __int64, LONGLONG, __int16 **))(*(_QWORD *)*v16 + 72i64))(
                       *v16,
                       v39,
                       2i64,
                       a1.QuadPart + 2048,
                       &v23);
    v18 = v17[1];
    v19 = *v17;
    v28 = *v17;
    v29 = v18;
    if ( v18 )
    {
      _InterlockedIncrement((volatile signed __int32 *)(v18 + 8));
      v18 = v29;
    }
    v9 = (__int64 *)(a1.QuadPart + 3392);
    if ( (__int64 *)(a1.QuadPart + 3392) != &v28 )
    {
      *v9 = v19;
      v28 = 0i64;
      sub_14122C310(a1.QuadPart + 3400, &v29);
      v18 = v29;
    }
    if ( v18 )
    {
      if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v18 + 8), 0xFFFFFFFF) == 1 )
      {
        v20 = v29;
        (**(void (__fastcall ***)(__int64))v29)(v29);
        if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v20 + 12), 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v29 + 8i64))(v29, 1i64);
      }
    }
    v21 = v40;
    if ( v40 )
    {
      if ( _InterlockedExchangeAdd(v40 + 2, 0xFFFFFFFF) == 1 )
      {
        (**(void (__fastcall ***)(volatile signed __int32 *))v21)(v21);
        if ( _InterlockedExchangeAdd(v21 + 3, 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)v21 + 8i64))(v21, 1i64);
      }
    }
    v22 = v42;
    if ( v42 )
    {
      if ( _InterlockedExchangeAdd(v42 + 2, 0xFFFFFFFF) == 1 )
      {
        (**(void (__fastcall ***)(volatile signed __int32 *))v22)(v22);
        if ( _InterlockedExchangeAdd(v22 + 3, 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)v22 + 8i64))(v22, 1i64);
      }
    }
    v14 = (__int64 (__fastcall ***)())sub_1411D7AB0(40i64, *v9 + 24);
    if ( !v14 )
      goto LABEL_49;
    *v14 = &off_147C0F9C8;
    v14[2] = (__int64 (__fastcall **)())sub_1411D9AC0();
    v15 = &off_147D93110;
  }
  *v14 = v15;
  if ( byte_1491545A9 )
    ((void (__fastcall *)(_QWORD))sub_1414A8C80)((LARGE_INTEGER)a1.QuadPart);
  v14[3] = 0i64;
  PerformanceCount = a1;
  if ( byte_1491545A9 )
    ((void (__fastcall *)(_QWORD))sub_1414A8C80)((LARGE_INTEGER)a1.QuadPart);
  sub_1415CE9C0(v14 + 3, &PerformanceCount);
  v14[4] = (__int64 (__fastcall **)())a1.QuadPart;
LABEL_49:
  LOBYTE(v13) = 1;
  sub_1445560C0(*v9, v13);
  if ( v23 )
    sub_14123C760((__int64)v23);
  if ( v34[0] )
    sub_14123C760(v34[0]);
}
//=================================================================//

//关键加密函数
//主要算法：循环异或 
//=================================================================//
__int64 __fastcall sub_144A52810(__int64 a1, __int64 a2, int a3)
{
  int v3; // ebx
  __int16 v5; // ax
  int v6; // ecx
  int v7; // eax
  int v8; // r15d
  __int64 v9; // rdx
  __int64 v10; // rbx
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  __int16 *v14; // rdi
  __int64 v15; // r12
  int v16; // r14d
  __int64 v17; // rbx
  unsigned int v18; // esi
  __int64 v19; // rax
  __int64 v20; // r8
  char *v21; // rcx
  int v22; // r8d
  int v23; // esi
  __int64 v24; // rbx
  char v25; // di
  int v26; // edi
  char v27; // bl
  int v28; // eax
  char v29; // bl
  int v30; // ecx
  int v31; // edx
  char v32; // di
  __int64 v33; // rbx
  __int64 v35; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v36; // [rsp+38h] [rbp-C8h]
  __int64 v37; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v38; // [rsp+48h] [rbp-B8h] BYREF
  unsigned int v39; // [rsp+50h] [rbp-B0h]
  __int64 v40[2]; // [rsp+58h] [rbp-A8h] BYREF
  int v41; // [rsp+68h] [rbp-98h]
  __int64 v42; // [rsp+70h] [rbp-90h]
  __int64 v43[2]; // [rsp+78h] [rbp-88h] BYREF
  __int64 v44[2]; // [rsp+88h] [rbp-78h] BYREF
  __int64 v45[2]; // [rsp+98h] [rbp-68h] BYREF
  __int64 v46[2]; // [rsp+A8h] [rbp-58h] BYREF
  __int64 v47[3]; // [rsp+B8h] [rbp-48h] BYREF
  char v48; // [rsp+D0h] [rbp-30h] BYREF
  __int64 v49; // [rsp+150h] [rbp+50h] BYREF
  char *v50; // [rsp+158h] [rbp+58h]
  int v51; // [rsp+160h] [rbp+60h]

  v3 = dword_148F52420;
  v41 = a3;
  v42 = a1;
  if ( dword_148F52420 <= 0 )
  {
    v6 = 0;
  }
  else
  {
    v5 = rand();
    v6 = v3 - 1;
    v7 = (int)(float)((float)((float)(v5 & 0x7FFF) * 0.000030518509) * (float)v3);
    if ( v7 < v3 - 1 )
      v6 = v7;
  }
  v39 = v6;
  v8 = *(_DWORD *)(qword_148F52418 + 4i64 * v6);
  v40[0] = 0i64;
  v40[1] = 0i64;
  sub_1411EB410(v40, (unsigned int)v8);
  if ( v8 > 0 )
  {
    v10 = (unsigned int)v8;
    do
    {
      v11 = rand();
      v12 = 63;
      v13 = (int)(float)((float)(v11 & 0x7FFF) * 0.0019531846);
      if ( v13 < 63 )
        v12 = v13;
      sub_1411D4170(v40, (unsigned int)aAbcdefghijklmn_0[v12]);
      --v10;
    }
    while ( v10 );
  }
  v49 = 0i64;
  if ( *(_DWORD *)(a2 + 8) )
  {
    v14 = *(__int16 **)a2;
    if ( !v14 )
    {
      v15 = 0i64;
      v50 = 0i64;
      v16 = 0;
      v51 = 0;
      goto LABEL_25;
    }
  }
  else
  {
    v14 = &chText;
  }
  v17 = -1i64;
  do
    ++v17;
  while ( v14[v17] );
  v51 = sub_141204120(0i64, v14, (unsigned int)v17);
  v18 = v51 + 1;
  if ( (unsigned int)(v51 + 1) > 0x80 )
  {
    v20 = v18;
    goto LABEL_21;
  }
  v19 = v49;
  if ( v49 )
  {
    v20 = 0i64;
LABEL_21:
    sub_1411EBA50(&v49, 0i64, v20, 1i64);
    v19 = v49;
  }
  v21 = &v48;
  if ( v19 )
    v21 = (char *)v19;
  v50 = v21;
  sub_1411FD7C0(v21, v18, v14, (unsigned int)(v17 + 1));
  v16 = v51;
  v15 = (__int64)v50;
LABEL_25:
  v37 = 0i64;
  v22 = 0;
  v38 = 0i64;
  if ( v16 < 0 )
  {
    sub_1411E5DF0((unsigned int)v16, v9, 0i64);
    JUMPOUT(0x144A52C87i64);
  }
  if ( v16 > 0 )
  {
    sub_1411B1AD0(1, 1, v16, (unsigned int)&v37, 0, (__int64)&v38 + 4);
    v22 = v38;
  }
  v23 = 0;
  if ( v16 > 0 )
  {
    v24 = 0i64;
    while ( 1 )
    {
      v25 = *(_BYTE *)(v24 + v15) ^ *(_BYTE *)(v40[0] + 2i64 * (v23 % v8));
      if ( v22 == HIDWORD(v38) )
        v22 = sub_1411B1210(257i64, &v37);
      LODWORD(v38) = v22 + 1;
      ++v23;
      ++v24;
      *(_BYTE *)(v22 + v37) = v25;
      if ( v24 >= v16 )
        break;
      v22 = v38;
    }
  }
  sub_1412D9E40(v47, &v37, 0i64);
  v26 = v41 % 0xFFFFFF;
  v35 = 0i64;
  v36 = 0i64;
  v27 = *(_BYTE *)v40[0] ^ ((unsigned int)(v41 % 0xFFFFFF) >> 16);
  v28 = sub_1411B1210(257i64, &v35);
  LODWORD(v36) = v28 + 1;
  *(_BYTE *)(v28 + v35) = v27;
  v29 = *(_BYTE *)(v40[0] + 2i64 * (1 % v8)) ^ BYTE1(v26);
  v30 = v36;
  if ( (_DWORD)v36 == HIDWORD(v36) )
    v30 = sub_1411B1210(257i64, &v35);
  LODWORD(v36) = v30 + 1;
  *(_BYTE *)(v30 + v35) = v29;
  v31 = v36;
  v32 = *(_BYTE *)(v40[0] + 2i64 * (2 % v8)) ^ v26;
  if ( (_DWORD)v36 == HIDWORD(v36) )
    v31 = sub_1411B1210(257i64, &v35);
  LODWORD(v36) = v31 + 1;
  *(_BYTE *)(v31 + v35) = v32;
  sub_1412D9E40(v46, &v35, 0i64);
  sub_1411E77B0(v45, L"%02d%06d", v39, (unsigned int)v16);
  sub_1411D6610(v44, v45, v46);
  sub_1411D6480(v43, v44, v40);
  v33 = v42;
  sub_1411D6480(v42, v43, v47);
  if ( v43[0] )
    sub_14123C760(v43[0]);
  if ( v44[0] )
    sub_14123C760(v44[0]);
  if ( v45[0] )
    sub_14123C760(v45[0]);
  if ( v46[0] )
    sub_14123C760(v46[0]);
  if ( v35 )
    sub_14123C760(v35);
  if ( v47[0] )
    sub_14123C760(v47[0]);
  if ( v37 )
    sub_14123C760(v37);
  if ( v49 )
    sub_14123C760(v49);
  if ( v40[0] )
    sub_14123C760(v40[0]);
  return v33;
}
//=================================================================//

//辅助函数
//字符串处理相关 
//=================================================================//
__int64 __fastcall sub_1411D4170(__int64 a1, __int16 a2)
{
  int v4; // ebx
  int v5; // eax

  if ( a2 )
  {
    v4 = *(_DWORD *)(a1 + 8);
    sub_1411B14A0(2, 2, (v4 <= 0) + 1, a1, a1 + 8, a1 + 12);
    v5 = v4 - 1;
    if ( v4 <= 0 )
      v5 = 0;
    *(_WORD *)(*(_QWORD *)a1 + 2i64 * v5) = a2;
    *(_WORD *)(*(_QWORD *)a1 + 2i64 * v5 + 2) = 0;
  }
  return a1;
}

__int64 __fastcall sub_1411D6480(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // eax
  unsigned int v7; // ebx
  __int64 v8; // [rsp+20h] [rbp-18h] BYREF
  int v9; // [rsp+28h] [rbp-10h]
  int v10; // [rsp+2Ch] [rbp-Ch]

  if ( *(int *)(a2 + 8) > 1 )
  {
    v6 = *(_DWORD *)(a3 + 8);
    v7 = v6 - 1;
    if ( !v6 )
      v7 = 0;
    sub_1411CA1E0(&v8, a2, v7);
    sub_1411D43E0(&v8, *(_QWORD *)a3, v7);
    *(_QWORD *)a1 = v8;
    *(_DWORD *)(a1 + 8) = v9;
    *(_DWORD *)(a1 + 12) = v10;
    return a1;
  }
  else
  {
    sub_1411CFD00(a1);
    return a1;
  }
}
//=================================================================//

//部分内存布局：
//=================================================================//
//内存地址 与 exe地址 对照 
00000000074A6000 - 00000000074A6110 : 0x07D93FD0 - 0x07D940E0
00000000074A6120 : 0x00FE0320 0x00FE0340 0x00FE0350
// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //
00000000074A6000  2F 00 00 00 35 00 00 00 49 00 00 00 37 00 00 00  /...5...I...7...  
00000000074A6010  3D 00 00 00 67 00 00 00 2F 00 00 00 67 00 00 00  =...g.../...g...  
00000000074A6020  21 00 00 00 2D 00 00 00 49 00 00 00 25 00 00 00  !...-...I...%...  
00000000074A6030  61 00 00 00 47 00 00 00 27 00 00 00 47 00 00 00  a...G...'...G...  
00000000074A6040  1F 00 00 00 3D 00 00 00 53 00 00 00 65 00 00 00  ....=...S...e...  
00000000074A6050  35 00 00 00 61 00 00 00 4F 00 00 00 4B 00 00 00  5...a...O...K...  
00000000074A6060  25 00 00 00 1F 00 00 00 21 00 00 00 45 00 00 00  %.......!...E...  
00000000074A6070  2B 00 00 00 3F 00 00 00 27 00 00 00 2B 00 00 00  +...?...'...+...  
00000000074A6080  4F 00 00 00 37 00 00 00 31 00 00 00 49 00 00 00  O...7...1...I...  
00000000074A6090  53 00 00 00 43 00 00 00 3B 00 00 00 45 00 00 00  S...C...;...E...  
00000000074A60A0  67 00 00 00 27 00 00 00 2F 00 00 00 25 00 00 00  g...'.../...%...  
00000000074A60B0  29 00 00 00 47 00 00 00 59 00 00 00 37 00 00 00  )...G...Y...7...  
00000000074A60C0  31 00 00 00 2D 00 00 00 21 00 00 00 2D 00 00 00  1...-...!...-...  
00000000074A60D0  45 00 00 00 31 00 00 00 2B 00 00 00 35 00 00 00  E...1...+...5...  
00000000074A60E0  3B 00 00 00 1F 00 00 00 3B 00 00 00 65 00 00 00  ;.......;...e...  
00000000074A60F0  3D 00 00 00 29 00 00 00 4F 00 00 00 4B 00 00 00  =...)...O...K...  
00000000074A6100  53 00 00 00 59 00 00 00 4B 00 00 00 43 00 00 00  S...Y...K...C...  
00000000074A6110  29 00 00 00 59 00 00 00 3F 00 00 00 65 00 00 00  )...Y...?...e...  
00000000074A6120  43 00 00 00 3F 00 00 00 61 00 00 00 00 00 00 00  C...?...a.......
//=================================================================//
