// 0x7D7110 @ 0x7D7110
// MoonSugarEffect decode: render-target pop helper ends current target, releases the top stack entry, then resumes previous/default RT group with no clear.
void sub_7D7110()
{
  NiRenderTargetGroup *v0; // eax

  if ( dword_B45D74 ) /*0x7d7110*/
  {
    sub_7D6B00(g_Renderer); /*0x7d711f*/
    sub_7D7030(); /*0x7d7124*/
    v0 = (NiRenderTargetGroup *)sub_7D6B70(); /*0x7d7129*/
    if ( !v0 ) /*0x7d7130*/
      v0 = g_Renderer->__vftable->super.GetDefaultRTGroup((NiRenderer *)g_Renderer); /*0x7d713d*/
    sub_7D6A80(g_Renderer, v0, kClear_NONE); /*0x7d7148*/
  }
}
