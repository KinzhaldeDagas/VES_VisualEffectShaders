// 0x76FB30 @ 0x76FB30
// MoonSugarEffect decode: semantic helper for declaration elements. Maps Oblivion semantic ids into declaration type/usage/index values, then forwards to the raw element setter at vtable +0x4C.
int __thiscall sub_76FB30(void *this, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // edx
  int v7; // eax

  v6 = 0; /*0x76fb35*/
  switch ( a4 ) /*0x76fb40*/
  {
    case 0: /*0x76fb40*/
      v7 = 0; /*0x76fb47*/
      break; /*0x76fb49*/
    case 1: /*0x76fb40*/
      v7 = 1; /*0x76fb4e*/
      break; /*0x76fb53*/
    case 2: /*0x76fb40*/
      v7 = 2; /*0x76fb55*/
      break; /*0x76fb5a*/
    case 3: /*0x76fb40*/
      v7 = 3; /*0x76fb5c*/
      break; /*0x76fb61*/
    case 4: /*0x76fb40*/
      v7 = 0xA; /*0x76fb63*/
      break; /*0x76fb68*/
    case 5: /*0x76fb40*/
      v7 = 5; /*0x76fb6a*/
      break; /*0x76fb6f*/
    case 6: /*0x76fb40*/
      v7 = 5; /*0x76fb71*/
      v6 = 1; /*0x76fb76*/
      break; /*0x76fb7b*/
    case 7: /*0x76fb40*/
      v7 = 5; /*0x76fb7d*/
      v6 = 2; /*0x76fb82*/
      break; /*0x76fb87*/
    case 8: /*0x76fb40*/
      v7 = 5; /*0x76fb89*/
      v6 = 3; /*0x76fb8e*/
      break; /*0x76fb93*/
    case 9: /*0x76fb40*/
      v7 = 5; /*0x76fb95*/
      v6 = 4; /*0x76fb9a*/
      break; /*0x76fb9f*/
    case 0xA: /*0x76fb40*/
      v7 = 5; /*0x76fba1*/
      v6 = 5; /*0x76fba6*/
      break; /*0x76fba8*/
    case 0xB: /*0x76fb40*/
      v7 = 5; /*0x76fbaa*/
      v6 = 6; /*0x76fbaf*/
      break; /*0x76fbb4*/
    case 0xC: /*0x76fb40*/
      v7 = 5; /*0x76fbb6*/
      v6 = 7; /*0x76fbbb*/
      break; /*0x76fbc0*/
    case 0xD: /*0x76fb40*/
      v7 = 6; /*0x76fbc2*/
      break; /*0x76fbc7*/
    case 0xE: /*0x76fb40*/
      v7 = 7; /*0x76fbc9*/
      break; /*0x76fbc9*/
    default:
      JUMPOUT(0x76FBF4); /*0x76fbf4*/
  }
  return (*(int (__thiscall **)(void *, int, int, int, int, int, int, int, _DWORD))(*(_DWORD *)this + 0x4C))( /*0x76fbf0*/
           this,
           a6,
           a2,
           a3,
           a4,
           a5,
           v7,
           v6,
           0);
}
