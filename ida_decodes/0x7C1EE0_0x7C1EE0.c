// 0x7C1EE0 @ 0x7C1EE0
// MoonSugarEffect decode: returns a BSRenderedTexture from texture manager in-use list to available list; it transfers list nodes rather than simply deleting the target.
void __thiscall sub_7C1EE0(BSTextureManager *this, BSRenderedTexture *a2)
{
  BSRenderedTexture *v2; // esi
  NiTPointerList_Node_void *start; // eax
  BSRenderedTexture *data; // edx
  NiTPointerList_Node_void *v6; // [esp+8h] [ebp-4h] BYREF

  v2 = a2; /*0x7c1ee2*/
  if ( a2 ) /*0x7c1eeb*/
  {
    start = this->unk10.start; /*0x7c1eed*/
    data = 0; /*0x7c1ef0*/
    a2 = 0; /*0x7c1ef4*/
    v6 = start; /*0x7c1ef8*/
    if ( start ) /*0x7c1efc*/
    {
      do /*0x7c1f13*/
      {
        if ( data ) /*0x7c1f02*/
        {
          v6 = start; /*0x7c1f23*/
          a2 = data; /*0x7c1f27*/
          goto LABEL_11; /*0x7c1f27*/
        }
        if ( *(BSRenderedTexture **)start->data == v2 ) /*0x7c1f09*/
          data = (BSRenderedTexture *)start->data; /*0x7c1f0b*/
        else
          start = start->next; /*0x7c1f0f*/
      }
      while ( start ); /*0x7c1f13*/
      v6 = 0; /*0x7c1f17*/
      a2 = data; /*0x7c1f1b*/
      if ( !data ) /*0x7c1f1f*/
        return; /*0x7c1f1f*/
LABEL_11:
      sub_5B1E20(this, (void **)&a2); /*0x7c1f2b*/
      sub_7AA860((BSTextureManager *)&this->unk10, &v6); /*0x7c1f3f*/
    }
  }
}
