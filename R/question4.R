#question 4
library(RPostgreSQL)
#selecting the driver for the database
drv <- dbDriver("PostgreSQL")
#creating a connection with local host postgreSQL 
connec <- dbConnect(drv, 
                    dbname = "jdbc_learning",
                    host = "localhost", 
                    port = 5432,
                    user = "postgres", 
                    password = "Iamrishav@0804")
#creating studnet table
createTable <- "CREATE TABLE STUDENT (ROLLNO INT ,COURSE VARCHAR(30))"
dbSendQuery(connec,createTable)

#inserting rows in the table
dbSendQuery(connec, "INSERT INTO STUDENT VALUES(1001,'Computer Science')")
dbSendQuery(connec, "INSERT INTO STUDENT VALUES(1002,'Electrical')")
dbSendQuery(connec, "INSERT INTO STUDENT VALUES(1003,'Mechanical')")
dbSendQuery(connec, "INSERT INTO STUDENT VALUES(1004,'Aerospace')")
dbSendQuery(connec, "INSERT INTO STUDENT VALUES(1005,'Elctronics')")

#displaying all the information stored in table
dbGetQuery(connec,"SELECT * FROM STUDENT")

#deleting all rows from the table
dbSendQuery(connec,"DELETE FROM STUDENT")

#dropping the table
dbSendQuery(connec,"DROP TABLE STUDENT")

dbDisconnect(connec)
dbUnloadDriver(drv)
