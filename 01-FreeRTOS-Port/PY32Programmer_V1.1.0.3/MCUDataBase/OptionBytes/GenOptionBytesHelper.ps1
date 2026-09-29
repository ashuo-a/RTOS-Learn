############################################################################################
# for ($i = 0; $i -le 0xF; $i++) {
#   # $address = 0x08000000 + 0x800 * $i                # Start
#   $address = 0x08000000 + 0x800 * ($i + 1) - 1      # End

#   "<option Value=`"0x$($i.ToString("X"))`" Display=`"0x$($address.ToString("X8"))`"/>"
# }

############################################################################################
"<fields>"
for ($i = 0; $i -le 15; $i++) {
  $address1 = 0x08000000 + 0x1000 * $i
  $address2 = 0x08000000 + 0x1000 * ($i + 1) - 1


  "<field>"
  "<name>WRP$($i.ToString())</name>"
  "<description>Write protection for 0x$($address1.ToString("X8")) ~ 0x$($address2.ToString("X8"))</description>"
  "<bitRange>[$($i.ToString()):$($i.ToString())]</bitRange>"
  "<options>"
  "<option Value=`"0`" Display=`"write protection enable`"/>"
  "<option Value=`"1`" Display=`"write protection disable`" Default=`"1`"/>"
  "</options>"
  "</field>"
}
"</fields>"