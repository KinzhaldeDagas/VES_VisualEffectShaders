// 0x77B610 @ 0x77B610
// MoonSugarEffect decode: NiDX9RenderState SetSamplerState cache. Uses sampler-state remap table, stores current/previous values, and calls D3D SetSamplerState only on change.
NiRenderStateSetting *__fastcall SetSamplerState(
        NiDX9RenderState *a1,
        int a2,
        D3DSAMPLERSTATETYPE a3,
        D3DSAMPLERSTATETYPE a4,
        DWORD a5,
        char a6)
{
  NiRenderStateSetting *result; // eax

  result = (NiRenderStateSetting *)*(unsigned __int16 *)(2 * a4 + 0xB427B0); /*0x77b615*/
  if ( (unsigned __int16)result < 5u ) /*0x77b621*/
  {
    result = &a1->member.SamplerStateSettings[5 * a3 + (unsigned __int16)result]; /*0x77b634*/
    if ( result->CurrentValue != a5 ) /*0x77b63d*/
    {
      if ( a6 ) /*0x77b644*/
        result->PreviousValue = result->CurrentValue; /*0x77b649*/
      result->CurrentValue = a5; /*0x77b64e*/
      return (NiRenderStateSetting *)a1->member.Device->lpVtbl->SetSamplerState(a1->member.Device, a3, a4, a5); /*0x77b661*/
    }
  }
  return result; /*0x77b664*/
}
