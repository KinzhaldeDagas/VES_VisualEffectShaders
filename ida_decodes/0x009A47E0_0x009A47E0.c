// 0x009A47E0 @ 0x009A47E0
// MoonSugarEffect decode: NiD3DSCM_Vertex constant-name lookup. Parses a constant name and looks it up in the global table at B32590; entries map names like World/WorldViewProj/BoneMatrix4/time to enum ids used by sub_9A56D0.
char __cdecl sub_9A47E0(char *Src, unsigned __int8 **a2, int a3)
{
  char result; // al
  int v4; // esi
  unsigned __int8 **i; // edi
  rsize_t v6; // [esp-8h] [ebp-114h]
  char Str1[260]; // [esp+4h] [ebp-108h] BYREF

  HIDWORD(v6) = a3; /*0x9a480a*/
  LODWORD(v6) = 0x104; /*0x9a480b*/
  result = sub_9A2480(Src, Str1, v6); /*0x9a4816*/
  if ( result ) /*0x9a4820*/
  {
    v4 = 0; /*0x9a4839*/
    if ( dword_B32584 ) /*0x9a4842*/
    {
      for ( i = (unsigned __int8 **)&unk_B32590; _strcmp((unsigned __int8 *)Str1, i[1]); i += 2 ) /*0x9a4844*/
      {
        if ( ++v4 >= (unsigned int)dword_B32584 ) /*0x9a4871*/
          return 0; /*0x9a4871*/
      }
      *a2 = *i; /*0x9a4890*/
      return 1; /*0x9a489d*/
    }
    else
    {
      return 0; /*0x9a4873*/
    }
  }
  return result; /*0x9a4822*/
}
