#a
rainfall2 <- read.csv("rainfall.csv", nrows = 10)
print(rainfall2)

#b
rainfall <- read.csv("rainfall1.csv", fill = TRUE)
rainfall_subset <- subset(rainfall, Rainfall.mm. > 20)

#c
mean_rainfall <- rainfall$Rainfall.mm. >= 3
print(mean(rainfall[mean_rainfall, "Rainfall.mm."]))

#d
d_subset <- subset(rainfall, Rainfall.mm. == 0 | Rainfall.mm. == 0.6)
print(d_subset)

#e
plot_dataset <- rainfall[!is.na(rainfall$Date), ]
with(plot_dataset, plot(Date, Rainfall.mm.))