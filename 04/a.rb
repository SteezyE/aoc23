#!/usr/bin/ruby

p $<.map{|x|x.gsub(/Card\s+\d+/,"").split("|").map{|y|y.scan(/\d+/).map(&:to_i)}.reduce(&:&)}.sum{|z| z.size > 0 ? 1<<(z.size-1) : 0}
