// 0x7DAB80 @ 0x7DAB80
void sub_7DAB80()
{
  switch ( ShaderPackage ) /*0x7dab94*/
  {
    case 1: /*0x7dab94*/
    case 2: /*0x7dab94*/
    case 3: /*0x7dab94*/
    case 4: /*0x7dab94*/
    case 5: /*0x7dab94*/
    case 6: /*0x7dab94*/
      return;
    case 7: /*0x7dab94*/
      if ( !UseHDR ) /*0x7dac37*/
        def_7DAB94(); /*0x7dac4f*/
      break; /*0x7dac4f*/
    default:
      JUMPOUT(0x7DAC53); /*0x7dac53*/
  }
}
