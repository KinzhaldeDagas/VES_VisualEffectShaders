// 0x74EAD0 @ 0x74EAD0
char *__thiscall sub_74EAD0(NiNode *this, int a2)
{
  char *result; // eax
  UInt32 numItems; // ebp
  int v5; // esi
  unsigned int v6; // ebx
  unsigned int i; // edi
  int v8; // ecx
  unsigned int v9; // ebx
  unsigned int j; // edi
  int v11; // ecx

  sub_722FC0(this, a2); /*0x74eada*/
  result = *(char **)&this->members.children.capacity; /*0x74eadf*/
  if ( result ) /*0x74eae7*/
  {
    result = *((char **)result + 0x1A); /*0x74eae9*/
    if ( result ) /*0x74eaee*/
      result = (char *)(*(int (__thiscall **)(char *, int))(*(_DWORD *)result + 0x80))(result, a2); /*0x74eafb*/
  }
  numItems = this->members.effects.numItems; /*0x74eafd*/
  while ( numItems ) /*0x74eb05*/
  {
    v5 = *(_DWORD *)(numItems + 8); /*0x74eb10*/
    result = (char *)(numItems + 8); /*0x74eb15*/
    numItems = *(_DWORD *)numItems; /*0x74eb18*/
    if ( v5 ) /*0x74eb1b*/
    {
      result = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 4))(v5); /*0x74eb28*/
      if ( result ) /*0x74eb2c*/
      {
        while ( result != dword_B408C8 ) /*0x74eb35*/
        {
          result = *((char **)result + 1); /*0x74eb37*/
          if ( !result ) /*0x74eb3c*/
            goto LABEL_9; /*0x74eb3c*/
        }
        v6 = *(unsigned __int16 *)(v5 + 0x5C); /*0x74eb60*/
        for ( i = 0; i < v6; ++i ) /*0x74eb60*/
        {
          if ( i < *(unsigned __int16 *)(v5 + 0x5C) ) /*0x74eb76*/
          {
            v8 = *(_DWORD *)(*(_DWORD *)(v5 + 0x54) + 4 * i); /*0x74eb7b*/
            if ( v8 ) /*0x74eb80*/
              result = (char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 0x80))(v8, a2); /*0x74eb8f*/
          }
        }
      }
      else
      {
LABEL_9:
        result = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 4))(v5); /*0x74eb3e*/
        if ( result ) /*0x74eb49*/
        {
          while ( result != dword_B40A28 ) /*0x74eb55*/
          {
            result = *((char **)result + 1); /*0x74eb57*/
            if ( !result ) /*0x74eb5c*/
              goto LABEL_24; /*0x74eb5c*/
          }
          v9 = *(unsigned __int16 *)(v5 + 0x22); /*0x74eb9a*/
          for ( j = 0; j < v9; ++j ) /*0x74eb9a*/
          {
            if ( j < *(unsigned __int16 *)(v5 + 0x22) ) /*0x74ebaa*/
            {
              v11 = *(_DWORD *)(*(_DWORD *)(v5 + 0x1C) + 4 * j); /*0x74ebaf*/
              if ( v11 ) /*0x74ebb4*/
                result = (char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v11 + 0x80))(v11, a2); /*0x74ebc3*/
            }
          }
        }
      }
    }
LABEL_24:
    ; /*0x74ebcc*/
  }
  return result; /*0x74ebd5*/
}
