#question 3
#a
df <- read.csv("/Users/rishav_raj/Desktop/my files/R/toy_dataset.csv")
df

#b
attach(df)

#c
nrow(subset(df,City="New York City"))
nrow(df[df$City == "New York City", ])
unique(df$City)

#d
df[order(-df$Income), ][1:5,]

#e
avg<- mean(df$Income)
nrow(subset(df,Income>avg))

#f
max(df$Income[df$Gender=="Female"])

#g
set.seed(2) # to repro..
random<-df[sample(nrow(df),10),]
random

#h
detach(df)
