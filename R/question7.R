#question7
alcohol <- read.table("tab_deline.txt", header = TRUE)

#a
alcohol_by_year <- split(alcohol, alcohol$Year)

for (i in c(1:7))
{
  year_data <- alcohol_by_year[[i]]
  max_beer_country <- year_data$Country[which.max(year_data$Beer)]
  min_wine_country <- year_data$Country[which.min(year_data$Wine)]
  print(max_beer_country)
  print(min_wine_country)
}

#b
alcohol_in_country <- split(alcohol, alcohol$Country)

for(j in c(1:2))
{
  print(summary(alcohol_in_country[[j]]))
}

#c

nz <- alcohol_in_country[[2]]
print(nz[nz$Beer > (mean(nz$Spirit)),"Beer"])

#d
for (i in c(1:7))
{
  print(summary(alcohol_by_year[[i]]))
}

#e
aus <- alcohol_in_country[[1]]
mean_beer_of_australia <- mean(aus$Beer)
mean_spirit_of_australia <- mean(aus$Spirit)
mean_wine_of_australia <- mean(aus$Wine)

aus_values <- c(mean_wine_of_australia, mean_spirit_of_australia, mean_beer_of_australia)
plot(aus_values, type = "o", col = "Blue")

mean_beer_of_nz <- mean(nz$Beer)
mean_spirit_of_nz <- mean(nz$Spirit)
mean_wine_of_nz <- mean(nz$Wine)
nz_values <- c(mean_wine_of_nz, mean_spirit_of_nz, mean_beer_of_nz)
lines(nz_values, col = "Green", type = "o",
      main = "Australia vs New Zeland alcohol consumption",
      xlabs = c("Wine", "Spirit", "Beer"))

