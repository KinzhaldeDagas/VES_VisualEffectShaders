// 0x007FAC40 @ 0x007FAC40
Lighting30Shader *__thiscall Lighting30Shader::Lighting30Shader(Lighting30Shader *this, int a2, int a3, int a4, int a5)
{
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  LONG (__stdcall *v12)(volatile LONG *); // ebp
  int v13; // edi
  int v14; // edi
  int v15; // edi
  Lighting30Shader *result; // eax

  BSShader::BSShader((BSShader *)this); /*0x7fac6b*/
  *(_DWORD *)this = &Lighting30Shader::`vftable'; /*0x7fac72*/
  *((_DWORD *)this + 0x1F) = 0; /*0x7fac7c*/
  *((_DWORD *)this + 0x20) = 0; /*0x7fac7f*/
  *((_DWORD *)this + 0x21) = 0; /*0x7fac85*/
  *((_DWORD *)this + 0x22) = 0; /*0x7fac8b*/
  *((_DWORD *)this + 0x23) = 0; /*0x7fac91*/
  *((_DWORD *)this + 0x24) = 0; /*0x7fac97*/
  *((_DWORD *)this + 0x25) = 0; /*0x7fac9d*/
  *((_DWORD *)this + 0x26) = 0; /*0x7faca3*/
  v6 = *((_DWORD *)this + 9); /*0x7faca9*/
  if ( v6 != a2 ) /*0x7facb7*/
  {
    if ( v6 ) /*0x7facbb*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) ) /*0x7facc1*/
        (**(void (__thiscall ***)(int, int))v6)(v6, 1); /*0x7facd7*/
    }
    *((_DWORD *)this + 9) = a2; /*0x7facdb*/
    if ( a2 ) /*0x7facde*/
      InterlockedIncrement((volatile LONG *)(a2 + 4)); /*0x7face4*/
  }
  v7 = *((_DWORD *)this + 0x23); /*0x7facea*/
  if ( v7 != a2 ) /*0x7facf2*/
  {
    if ( v7 ) /*0x7facf6*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) ) /*0x7facfc*/
        (**(void (__thiscall ***)(int, int))v7)(v7, 1); /*0x7fad12*/
    }
    *((_DWORD *)this + 0x23) = a2; /*0x7fad16*/
    if ( a2 ) /*0x7fad1c*/
      InterlockedIncrement((volatile LONG *)(a2 + 4)); /*0x7fad22*/
  }
  v8 = *((_DWORD *)this + 0x24); /*0x7fad28*/
  if ( v8 != a3 ) /*0x7fad34*/
  {
    if ( v8 ) /*0x7fad38*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) ) /*0x7fad3e*/
        (**(void (__thiscall ***)(int, int))v8)(v8, 1); /*0x7fad54*/
    }
    *((_DWORD *)this + 0x24) = a3; /*0x7fad58*/
    if ( a3 ) /*0x7fad5e*/
      InterlockedIncrement((volatile LONG *)(a3 + 4)); /*0x7fad64*/
  }
  v9 = *((_DWORD *)this + 0x25); /*0x7fad6a*/
  if ( v9 != a4 ) /*0x7fad76*/
  {
    if ( v9 ) /*0x7fad7a*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) ) /*0x7fad80*/
        (**(void (__thiscall ***)(int, int))v9)(v9, 1); /*0x7fad96*/
    }
    *((_DWORD *)this + 0x25) = a4; /*0x7fad9a*/
    if ( a4 ) /*0x7fada0*/
      InterlockedIncrement((volatile LONG *)(a4 + 4)); /*0x7fada6*/
  }
  v10 = *((_DWORD *)this + 0x26); /*0x7fadac*/
  if ( v10 != a5 ) /*0x7fadb8*/
  {
    if ( v10 ) /*0x7fadbc*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) ) /*0x7fadc2*/
        (**(void (__thiscall ***)(int, int))v10)(v10, 1); /*0x7fadd8*/
    }
    *((_DWORD *)this + 0x26) = a5; /*0x7faddc*/
    if ( a5 ) /*0x7fade2*/
      InterlockedIncrement((volatile LONG *)(a5 + 4)); /*0x7fade8*/
  }
  v11 = *((_DWORD *)this + 0x1F); /*0x7fadee*/
  v12 = InterlockedDecrement; /*0x7fadf3*/
  if ( v11 ) /*0x7fadf9*/
  {
    if ( !v12((volatile LONG *)(v11 + 4)) ) /*0x7fadff*/
      (**(void (__thiscall ***)(int, int))v11)(v11, 1); /*0x7fae11*/
    *((_DWORD *)this + 0x1F) = 0; /*0x7fae13*/
  }
  v13 = *((_DWORD *)this + 0x20); /*0x7fae16*/
  if ( v13 ) /*0x7fae1e*/
  {
    if ( !v12((volatile LONG *)(v13 + 4)) ) /*0x7fae24*/
      (**(void (__thiscall ***)(int, int))v13)(v13, 1); /*0x7fae36*/
    *((_DWORD *)this + 0x20) = 0; /*0x7fae38*/
  }
  v14 = *((_DWORD *)this + 0x21); /*0x7fae3e*/
  if ( v14 ) /*0x7fae46*/
  {
    if ( !v12((volatile LONG *)(v14 + 4)) ) /*0x7fae4c*/
      (**(void (__thiscall ***)(int, int))v14)(v14, 1); /*0x7fae5e*/
    *((_DWORD *)this + 0x21) = 0; /*0x7fae60*/
  }
  v15 = *((_DWORD *)this + 0x22); /*0x7fae66*/
  if ( v15 ) /*0x7fae6e*/
  {
    if ( !v12((volatile LONG *)(v15 + 4)) ) /*0x7fae74*/
      (**(void (__thiscall ***)(int, int))v15)(v15, 1); /*0x7fae86*/
    *((_DWORD *)this + 0x22) = 0; /*0x7fae88*/
  }
  *((_DWORD *)this + 0x27) = 0; /*0x7fae90*/
  dword_B46964 = 0; /*0x7fae9e*/
  dword_B46968 = 0; /*0x7faea3*/
  dword_B4696C = 0; /*0x7faea8*/
  dword_B46970 = 0; /*0x7faead*/
  dword_B46974 = 0; /*0x7faeb2*/
  dword_B46978 = 0; /*0x7faeb7*/
  dword_B4697C = 0; /*0x7faebc*/
  dword_B46980 = 0; /*0x7faec1*/
  byte_B46984 = 0; /*0x7faec6*/
  _memset(byte_B46930, 0, 0x31); /*0x7faecb*/
  result = this; /*0x7faeda*/
  if ( ShaderPackage < 7 ) /*0x7faedc*/
    dword_B2DCFC = 8; /*0x7faede*/
  return result; /*0x7faee8*/
}
