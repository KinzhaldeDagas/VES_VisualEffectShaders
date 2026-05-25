// 0x7D71C0 @ 0x7D71C0
// MoonSugarEffect decode: NiRenderer_BeginScene1 path sets SceneState1 when needed, then StartUsingRenderTarget for supplied/default target group.
_DWORD *__cdecl NiRenderer_BeginScene1(ClearFlags a1, NiRenderTargetGroup *a2)
{
  NiRenderer *v2; // ecx
  UInt32 *p_SceneState1; // esi

  v2 = (NiRenderer *)g_Renderer; /*0x7d71c0*/
  p_SceneState1 = &g_Renderer->member.super.SceneState1; /*0x7d71ce*/
  if ( !*p_SceneState1 && !v2->members.SceneState2 && v2->__vftable->BeginScene(v2) ) /*0x7d71e7*/
    *p_SceneState1 = 1; /*0x7d71ed*/
  return (_DWORD *)StartUsingRenderTarget(a2, a1); /*0x7d7205*/
}
