#!/usr/bin/ruby

a = $<.each_with_index.map{|x,i|(i+2..(i+1+x.gsub(/Card\s+\d+/,"").split("|").map{|y|y.scan(/\d+/).map(&:to_i)}.reduce(&:&).size)).to_a}
h = [0] * a.size
(0...a.size).each{|i| a[i].each{|x| h[x-1]+=h[i]+1}}
p h.sum + a.size
