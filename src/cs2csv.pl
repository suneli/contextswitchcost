while(<STDIN>){
   chomp;
   ($t,$a,$s,$tim) = split/,/;
   $h{$t}{$a}{$s} = $tim;
   $a{$a} = 1;
   $s{$s} = 1;
}
for $t (sort keys %h){
  open my $out, ">$t.csv" or die $!;
  @a = sort { $a <=> $b } keys %a;
  @s = sort { $b <=> $a } keys %s;
  print $out ",".join(",",@a)."\n";  
  for $s (@s){
     print $out "$s,";
     print $out join(",", map { $h{$t}{$_}{$s} ? $h{$t}{$_}{$s}:"" } @a)."\n";
  }
  close $out;
}

