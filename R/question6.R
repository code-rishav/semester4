#question6
#a
data("iris")
summary(iris)
head(iris)

#b,c
data <- subset(iris,Species=="setosa")
plot(data$Petal.Length,data$Petal.Width,xlab = "Petal Length",ylab = "Petal Width",main = "comparison for length and width")

#d
hist(iris$Petal.Length)

#e
data<- subset(iris,Species="versicolor")
boxplot(data$Petal.Width)
