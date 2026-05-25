// 0x0076F590 @ 0x0076F590
// MoonSugarEffect decode: generic declaration element copy/pack dispatcher used by 0x76FE20. Uses declaration semantic/type to copy positions, normals, colors, UVs, skin data into the mapped vertex stream.
void __stdcall sub_76F590(int a1, NiGeometry *a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v8; // edx

  v7 = *(_DWORD *)(a5 + 0xC); /*0x76f5aa*/
  if ( v7 != 0x11 ) /*0x76f5b8*/
  {
    if ( *(_DWORD *)(*(_DWORD *)(dword_B42700 + 4) + 4 * v7) ) /*0x76f5d3*/
    {
      v8 = *(_DWORD *)(a5 + 8); /*0x76f5e4*/
      switch ( v8 ) /*0x76f600*/
      {
        case 0xFFFFFFFF: /*0x76f600*/
          return;
        case 0: /*0x76f600*/
        case 3: /*0x76f600*/
        case 4: /*0x76f600*/
        case 0xD: /*0x76f600*/
        case 0xE: /*0x76f600*/
          goto LABEL_17;
        case 1: /*0x76f600*/
          if ( a4 ) /*0x76f647*/
          {
            switch ( *(_WORD *)(a4 + 0x24) ) /*0x76f659*/
            {
              case 1: /*0x76f659*/
              case 2: /*0x76f659*/
              case 3: /*0x76f659*/
                goto LABEL_18;
              case 4: /*0x76f659*/
                def_76F659(a4, a1, (int)a2, a3, a4, a5, 3, a7); /*0x76f6d0*/
                return; /*0x76f6d0*/
              default:
                JUMPOUT(0x76F6D3); /*0x76f6d3*/
            }
          }
          return; /*0x76f647*/
        case 2: /*0x76f600*/
          if ( a4 ) /*0x76f6e1*/
          {
            if ( *(_DWORD *)(a4 + 0x10) ) /*0x76f6e7*/
            {
              switch ( *(_WORD *)(a4 + 0x24) ) /*0x76f702*/
              {
                case 1: /*0x76f702*/
                case 2: /*0x76f702*/
                case 3: /*0x76f702*/
LABEL_18:
                  JUMPOUT(0x76F834); /*0x76f834*/
                case 4: /*0x76f702*/
                  def_76F702(a1, (int)a2, a3, a4, a5, 0x1C, a7); /*0x76f770*/
                  break; /*0x76f770*/
                default:
                  JUMPOUT(0x76F773); /*0x76f773*/
              }
            }
          }
          return; /*0x76f770*/
        case 5: /*0x76f600*/
        case 6: /*0x76f600*/
        case 7: /*0x76f600*/
        case 8: /*0x76f600*/
        case 9: /*0x76f600*/
        case 0xA: /*0x76f600*/
        case 0xB: /*0x76f600*/
        case 0xC: /*0x76f600*/
          sub_7282F0(a2, v8 - 5); /*0x76f79f*/
LABEL_17:
          JUMPOUT(0x76F82C); /*0x76f82c*/
        default:
          JUMPOUT(0x76F7E6); /*0x76f7e6*/
      }
    }
  }
}
