#question5
df <- read.csv("/Users/rishav_raj/Desktop/my files/R/rainfall.csv")
#a
head(df,10)
#b
subst <- subset(df,Rainfall>20)
subst
#c
mean(df[df$Rainfall>=4,"Rainfall"])

#d
rain <- subset(df,Rainfall==0 | Rainfall==0.6)
rain <- rain$Rainfall
v <- as.vector(rain)
v


