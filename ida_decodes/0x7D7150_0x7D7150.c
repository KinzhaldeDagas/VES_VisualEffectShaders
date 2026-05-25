// 0x7D7150 @ 0x7D7150
// MoonSugarEffect decode: drains all render-target stack entries and ends any active RT group before scene end.
char sub_7D7150()
{
  int v0; // eax
  LONG (__stdcall *v1)(volatile LONG *); // ebx
  int v2; // esi
  _DWORD *v3; // edi

  v0 = dword_B45D74; /*0x7d7150*/
  if ( dword_B45D74 ) /*0x7d7150*/
  {
    v1 = InterlockedDecrement; /*0x7d715a*/
    do /*0x7d71a1*/
    {
      --v0; /*0x7d7162*/
      v2 = *(_DWORD *)(4 * v0 + 0xB45D78); /*0x7d7165*/
      v3 = (_DWORD *)(4 * v0 + 0xB45D78); /*0x7d716e*/
      dword_B45D74 = v0; /*0x7d7175*/
      if ( v2 ) /*0x7d717a*/
      {
        if ( !v1((volatile LONG *)(v2 + 4)) ) /*0x7d7180*/
          (**(void (__thiscall ***)(int, int))v2)(v2, 1); /*0x7d7192*/
        v0 = dword_B45D74; /*0x7d7194*/
        *v3 = 0; /*0x7d7199*/
      }
    }
    while ( v0 ); /*0x7d71a1*/
  }
  if ( g_Renderer->member.super.IsReady ) /*0x7d71ac*/
    LOBYTE(v0) = sub_7D6B00(g_Renderer); /*0x7d71b5*/
  return v0; /*0x7d71ba*/
}
