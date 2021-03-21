#!/usr/bin/perl
use strict;
use warnings;
use bignum ;
my %nodes;
my $softwareTime;
my $hardwareTime;
my $ins;
my $virtualReg;  
my @nodeNum;
my @opcode;
my $saveval;

use instructions;

my $fName = $ARGV[0];
my $mult_jmp_addr = $ARGV[1];
	$softwareTime = 0;
	$nodeHit	   = 0;
	$virtualReg = 0;
	$ins= 0;
	$hardwareTime = 0;
	$mactime  = 0;
	$memorySpace = 0;
	open (my $logCompute, '>', $fName.'_node_values.log'); 
	open (my $node_val, '>', $fName.'_node_values.temp'); 
	open(IN, "<", $fName) ;
	while(<IN>){
	chomp;
	$a = 0.1;
	$b = 0.7; 
	$c = 0.6;
	if($_ =~ /^\*NODE/)
	   {
		@nodeNum = split (/:/, $_);
		if ($nodeNum[1] != '1') 
		   {
			if ($mactime eq 1) 
			{
				$hardwareTime = a * $softwareTime;
			} else {
				$hardwareTime = b * $softwareTime - c * $virtualReg;
			}
			$saveValue = $nodeNum[1] - 1;
			$nodes{$saveValue}{'softwareTime'} 	= $softwareTime;
			$nodes{$saveValue}{'node_count'} 	= $nodeHit;
			$nodes{$saveValue}{'hardwareTime'} 	= $hardwareTime;
			$nodes{$saveValue}{'virtualReg'}  = $virtualReg;
			$nodes{$saveValue}{'node_mem_space'} 	= $memorySpace;
			$nodes{$saveValue}{'ins'} = $ins;
			$nodes{$saveValue}{'mactime'} 	= $mactime;
		   }
		$nodes{key} = $nodeNum[1]; 
		$nodes{$nodeNum[1]}{'part'} = $nodeNum[2];
		$softwareTime = 0;
		$hardwareTime = 0;
		$mactime  = 0;
		$ins= 0;
		$nodeHit = 0;
		$memorySpace = 0;
		$virtualReg = 0;
		
	  }	

	if($_ =~ /^[0-9|A-Z]{4}/) 
	   { 
		$ins = $ins + 1;
		if ($_ =~ /(fls|e2pprom).*(write|read)/i)
		{
			$nodeHit = $nodeHit + 1;
		}
			
		if ($_ =~ /$mult_jmp_addr/)
		{
			$mactime  = 1;
			$softwareTime = $softwareTime + $executionTime;
		}

		if ($_ =~ /__r[0-9]/)
		{
			$virtualReg = $virtualReg + 1;
		}

		@opcode = split (/[\s+]/, $_);
		if (@opcode[1] =~ /8[0-9|A-Z]/) {
			$opcode[1] = substr $opcode[1], 0 , 1;
		}
		
		$softwareTime = $softwareTime +  $instructions{$opcode[1]}{cycles};
		$memorySpace = $memorySpace + $instructions{$opcode[1]}{bytes};
	   }
	}	

	if ($mactime eq 1) 
	{
		$hardwareTime = a * $softwareTime;
	} else {
		$hardwareTime = b * $softwareTime - c * $virtualReg;
	}
	$nodes{$nodeNum[1]}{'softwareTime'} = $softwareTime;
	$nodes{$nodeNum[1]}{'mactime'} 	= $mactime;
	$nodes{$nodeNum[1]}{'hardwareTime'} = $hardwareTime;
	$nodes{$nodeNum[1]}{'node_mem_space'} 	= $memorySpace;
	$nodes{$nodeNum[1]}{'virtualReg'} = $virtualReg;
	$nodes{$nodeNum[1]}{'ins'}= $ins;
	$nodes{$nodeNum[1]}{'node_count'} 	= $nodeHit;
	close $node_val;
	close $out;
	foreach my $k_node (sort keys %nodes) {
	   print $logCompute $k_node."\n";
	   print $logCompute $nodes{$k_node}{'softwareTime'}."\n";
	   print $logCompute $nodes{$k_node}{'hardwareTime'}."\n";
	   print $logCompute "\n";
	}
	close $logCompute;
