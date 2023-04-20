while(<STDIN>){
  print "$3,$1,$2,$4\n" if m/array_size\s*=\s*(\d+),\s*stride\s*=\s*(\d+),\s*min\s*(time[12])\s*=\s*([\.\d]+)/ && !$hash{$3.','.$1.','.$2};
  $hash{$3.','.$1.','.$2}=1;
}
