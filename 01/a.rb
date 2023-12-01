#!/usr/bin/ruby

p $<.map{|s| s.scan(/\d/) * ''}.sum{|s| s[0].to_i*10+s[-1].to_i}
