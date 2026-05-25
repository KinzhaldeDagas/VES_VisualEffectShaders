// 0x7D70A0 @ 0x7D70A0
// MoonSugarEffect decode: StartUsingRenderTarget ends current target if needed, begins requested/default RT group, then pushes the target into B45D78 stack if depth B45D74 < 10.
int __cdecl StartUsingRenderTarget(NiRenderTargetGroup *a1, ClearFlags clearFlags)
{
  NiDX9Renderer *v2; // esi
  NiRenderTargetGroup *v3; // edi
  NiRenderTargetGroup *v4; // eax
  int result; // eax

  v2 = g_Renderer; /*0x7d70a1*/
  v3 = a1; /*0x7d70a8*/
  if ( !a1 ) /*0x7d70ae*/
    v3 = v2->__vftable->super.GetDefaultRTGroup((NiRenderer *)v2); /*0x7d70b9*/
  if ( v2->member.super.IsReady ) /*0x7d70bb*/
    sub_7D6B00(v2); /*0x7d70c6*/
  v4 = v3; /*0x7d70cd*/
  if ( !v3 ) /*0x7d70cf*/
    v4 = g_Renderer->__vftable->super.GetDefaultRTGroup((NiRenderer *)g_Renderer); /*0x7d70dc*/
  sub_7D6A80(g_Renderer, v4, clearFlags); /*0x7d70ea*/
  result = dword_B45D74; /*0x7d70ef*/
  if ( (unsigned int)dword_B45D74 < 0xA ) /*0x7d70f7*/
  {
    result = (int)NiSmartPointer_Set__((Ni2DBuffer **)(4 * result + 0xB45D78), (Ni2DBuffer *)v3); /*0x7d7101*/
    ++dword_B45D74; /*0x7d7106*/
  }
  return result; /*0x7d710d*/
}
