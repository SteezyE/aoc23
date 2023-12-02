#!/usr/bin/ruby

p $<.sum{|s|a=s.split ": "; r,g,b=[],[],[] 
	 a[1].split(";").map{|s| s.scan(/\d+ \w/).map(&:split).each{|x|eval x[1]+"<<"+x[0]}}
	 r.max * g.max * b.max}
