library(RPostgreSQL)
rv <- dbDriver("PostgreSQL")
connec <- dbConnect(drv, 
                    dbname = "jdbc_learning",
                    host = "localhost", 
                    port = 5432,
                    user = "postgres", 
                    password = "Iamrishav@0804")
mood<-readline(prompt="Enter mood: ")
query<-paste0("SELECT * FROM SONGS WHERE MOOD='",mood,"'")
results<-dbGetQuery(connec,query)

if(nrow(results)==0){
  cat("Sorry no songs found")
}else{
  cat("songs for your mood:\n")
  for(i in 1:norw(results))
    cat(paste0(i,'-',result$songname[i],'\n'))
}
