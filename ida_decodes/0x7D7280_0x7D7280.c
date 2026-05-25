// 0x7D7280 @ 0x7D7280
// MoonSugarEffect decode: NiRenderer_BeginScene path sets SceneState2 when needed, then StartUsingRenderTarget for supplied/default target group.
_DWORD *__cdecl NiRenderer_BeginScene(ClearFlags a1, NiRenderTargetGroup *a2)
{
  NiRenderer *v2; // ecx
  UInt32 *p_SceneState2; // esi

  v2 = (NiRenderer *)g_Renderer; /*0x7d7280*/
  p_SceneState2 = &g_Renderer->member.super.SceneState2; /*0x7d728e*/
  if ( !*p_SceneState2 && !v2->members.SceneState1 && v2->__vftable->BeginScene(v2) ) /*0x7d72a7*/
    *p_SceneState2 = 1; /*0x7d72ad*/
  return (_DWORD *)StartUsingRenderTarget(a2, a1); /*0x7d72c5*/
}
