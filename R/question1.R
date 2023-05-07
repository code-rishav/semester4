# practical lists
#question1
#a
n <- 1:4
n
ch <- c('a','f','r','h')
ch
lg <- c(TRUE,FALSE,FALSE,TRUE)
lg

#b
x <- 1:10
y <- 11:20
res <- 2*x + y -3
res

#c
odds <- seq(101,500,2)
odds

#d
mean(odds)
sd(odds)

#e
combination <- list(
  1:10, array(10:20), list(30:40)
)
combination

#f
m1 <- matrix(1:10,nrow=5,ncol = 2)
m1
m2 <- matrix(11:20,nrow=5,ncol=2)
m2
mat_mul<-m1 * m2
mat_mul

#g
colMeans(m1)
colMeans(m2)

#h
cbind(m1,m2)
rbind(m1,m2)

#i
mat <- matrix(1:12,nrow=3,ncol=4)
mat
mat2<-matrix(mat,nrow=2,ncol=4) # forceful warning shown
mat2
x
