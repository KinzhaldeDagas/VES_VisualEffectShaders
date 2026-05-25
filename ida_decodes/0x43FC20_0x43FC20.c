// 0x43FC20 @ 0x43FC20
// TES cleanup/streaming critical-section path; calls SpeedTree cache prune 0x55E390(1) before and after heap/cell cleanup.
char __thiscall sub_43FC20(TES *this, char a2)
{
  DWORD v2; // edi
  char result; // al
  DWORD CurrentThreadId; // eax

  if ( !byte_B350D5 || (nullsub_returnTrue_0arg(), result) ) /*0x43fc33*/
  {
    nullsub_returnTrue_0arg(); /*0x43fc3b*/
    EnterCriticalSection(&CriticalSection); /*0x43fc48*/
    CurrentThreadId = GetCurrentThreadId(); /*0x43fc4e*/
    ++dword_B353FC; /*0x43fc54*/
    dword_B353F8 = CurrentThreadId; /*0x43fc5d*/
    sub_55E390(1); /*0x43fc62*/
    sub_7B84E0(); /*0x43fc6a*/
    if ( dword_B35300 ) /*0x43fc6f*/
    {
      if ( this->unkA9 || a2 ) /*0x43fc87*/
        sub_4A25F0((_DWORD *)dword_B35300); /*0x43fc89*/
    }
    MemoryHeap_FreeUnusedPagesStart(v2); /*0x43fc8e*/
    sub_55E390(1); /*0x43fc95*/
    if ( dword_B353FC-- == 1 ) /*0x43fc9d*/
      dword_B353F8 = 0; /*0x43fca6*/
    LeaveCriticalSection(&CriticalSection); /*0x43fcb5*/
    nullsub_returnTrue_0arg(); /*0x43fcbd*/
  }
  return result; /*0x43fcc5*/
}
