--[[
assume these scripts are inside a trigger
assume each onTrigger function is in a seperate trigger because parallel is a bitch

built in methods below for clarity
]]--
Move(function(GroupId: number, X: number, Y: number, Duration: number, EasingStyle: enum?)
end)

Pulse(function(Channel: enum, GroupId: number, Color: color3, FadeIn: number, Hold: number, FadeOut: number)
end)

onTrigger(function() -- built in method runs when you hit the trigger
  Move( -- built in move method
  21, -- group id
  30, -- x, side note moving relative to world coordinates would be dope
  -20, -- y
  999, -- duration in seconds
  enum.EasingStyle.BounceIn -- easing style using enums (nil or empty for linear)
)
end)

-- who needs spawn triggers when you have loops?
onTrigger(function() -- this will pulse the background every second 12 times
  for i = 1, 12 do
    Pulse(
        enum.Channel.bg, -- colour channel
        nil, -- group id
        fromRGB(255, 40, 190), -- script editor feature on hover lets you pick colours in hsv
        0, -- fade in seconds
        0.05, -- hold seconds
        1.40 -- fade out seconds
      )
    Delay(1) -- yields in seconds
  end
end)

-- how about passing parameters as a table?
onTrigger(function()
  Pulse({
    Channel = enum.Channel.bg,
    Color = fromRGB(255, 40, 190),
    FadeIn = 0.2,
    Hold = 0.05,
    FadeOut = 1.4
  })
end)
