for(my $i=1;$i<0x10000000;$i*=2){
   for(my $j=1;$j<=$i;$j*=2){
      `sudo ./measureSingle -n $i -s $j >> out.txt`;
      `sudo ./measureSwitch -n $i -s $j >> out.txt`;
   }
}
