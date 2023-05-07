# Load the UScereal dataset
library(MASS)
data(UScereal)

# a) Relationship between manufacturer and shelf
plot(UScereal$Manufacturer, UScereal$Shelf, main = "Relationship between manufacturer and shelf")

# b) Relationship between fat and vitamins
plot(UScereal$Fat, UScereal$Vitamins, main = "Relationship between fat and vitamins")

# c) Relationship between fat and shelf
plot(UScereal$Fat, UScereal$Shelf, main = "Relationship between fat and shelf")

# d) Relationship between carbohydrates and sugars
plot(UScereal$Carbo, UScereal$Sugars, main = "Relationship between carbohydrates and sugars")

# e) Relationship between fibre and manufacturer
plot(UScereal$Fiber, UScereal$Manufacturer, main = "Relationship between fibre and manufacturer")

# f) Relationship between sodium and sugars
plot(UScereal$Sodium, UScereal$Sugars, main = "Relationship between sodium and sugars")
