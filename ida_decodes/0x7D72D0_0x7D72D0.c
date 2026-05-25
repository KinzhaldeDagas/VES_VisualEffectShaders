// 0x7D72D0 @ 0x7D72D0
// MoonSugarEffect decode: NiRenderer_EndScene drains the render-target stack, ends D3D scene only for the SceneState2/SceneState1 combination, then clears SceneState2.
char NiRenderer_EndScene()
{
  NiDX9Renderer *v0; // esi
  char result; // al

  v0 = g_Renderer; /*0x7d72d1*/
  result = sub_7D7150(); /*0x7d72d7*/
  if ( v0->member.super.SceneState2 == 1 && !v0->member.super.SceneState1 ) /*0x7d72e5*/
  {
    result = v0->__vftable->super.EndScene((NiRenderer *)v0); /*0x7d72f8*/
    if ( result ) /*0x7d72fc*/
      v0->member.super.SceneState2 = 0; /*0x7d72fe*/
  }
  return result; /*0x7d7308*/
}
