#!/usr/bin/ruby

h = %w(one two three four five six seven eight nine ! 1 2 3 4 5 6 7 8 9)
p $<.map{|s| s.scan(/(?=(\d|one|two|three|four|five|six|seven|eight|nine))/).flatten.map{|x| h.find_index(x) % 10 + 1 } * ''}.sum{|s| s[0].to_i*10+s[-1].to_i}
