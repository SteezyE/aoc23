#!/usr/bin/ruby

h = {"r"=>12, "g"=>13, "b"=>14}
p $<.sum{|s|a=s.split ": "   
	 a[1].split(";").map{|s| s.scan(/\d+ \w/).map(&:split).map{|x|x[0].to_i <= h[x[1]]}}.flatten.reduce(:&) ? a[0][/\d+/].to_i : 0}
