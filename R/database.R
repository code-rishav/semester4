library(DBI)
library(RSQLite)
library(RMySQL)
library(RPostgreSQL)

driver <- dbDriver("MySQL")
db_file <- "path/to/MySQL/db1"
conn <- dbConnect(driver, db_file)

query <- "SHOW TABLES"
dbGetQuery(conn,query)

count<- "ELECT COUNT(*) FROM STUDENT"
dbGetQuery(conn,query)

dbDisconnect(conn)
dbUnloadDriver(driver)