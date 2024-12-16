-- this sucks and is dumb
local testString = "meow"
local if_total = 0
local switch_total = 0

local cases = {
    ["j"] = function() end,
    ["jooj"] = function() end,
    ["meoi"] = function() end,
    ["aue"] = function() end,
    ["meow"] = function() end,
}

local function benchmark_if(str)
    local start_time = os.clock()
    if str == "j" then
    elseif str == "jooj" then
    elseif str == "meoi" then
    elseif str == "aue" then
    elseif str == "meow" then
    end
    if_total = if_total + (os.clock() - start_time)
end

local function benchmark_switch(str)
    local start_time = os.clock()
    if cases[str] then
        cases[str]()
    else
        print("oops")
    end
    switch_total = switch_total + (os.clock() - start_time)
end

for j = 1, 10 do
    for i = 1, 10000 do
        benchmark_if(testString)
    end
    
    for i = 1, 10000 do
        benchmark_switch(testString)
    end
-- % starts the string formatter, d means number, .6f means only display 6 numbers after decimal of float
    print(string.format("Run %d - if total: %.6f", j, if_total))
    print(string.format("Run %d - switch total: %.6f\n", j, switch_total))
    
    if_total = 0
    switch_total = 0
end
