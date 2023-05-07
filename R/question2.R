#question 2
data("airquality")
summary(airquality)

#a
head(airquality)
#b
dim(airquality)

#c
#to find all the rows including NA values
nrow(airquality) # for general count
nrow(na.omit(airquality))

#d
subset(airquality, Temp >= 70 & Temp <= 80)

#e
nrow(subset(airquality, Month == 5))

#f
head(airquality, n = 10)

#g
summary(airquality$Wind)

#h
airquality[order(-airquality$Temp), ]

#i
new_observation <- data.frame(Ozone = 25, Solar.R = 150, Wind = 88, Temp = 45, Month = 6, Day = 5)
airquality <- rbind(airquality, new_observation)
