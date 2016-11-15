CREATE DATABASE  IF NOT EXISTS `carrental` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `carrental`;
-- MySQL dump 10.13  Distrib 5.6.17, for Win64 (x86_64)
--
-- Host: sql5.freemysqlhosting.net    Database: sql5120702
-- ------------------------------------------------------
-- Server version	5.5.49-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `cars`
--

DROP TABLE IF EXISTS `cars`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cars` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `image` mediumblob,
  `make` varchar(255) NOT NULL,
  `model` varchar(255) NOT NULL,
  `year` varchar(255) NOT NULL,
  `condition` varchar(255) NOT NULL,
  `mileage` varchar(255) NOT NULL,
  `type` varchar(255) NOT NULL,
  `availability` varchar(10) NOT NULL,
  `priceperday` double NOT NULL,
  `stores_ID` int(11) NOT NULL,
  `description` varchar(400) DEFAULT NULL,
  `quantity_available` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`stores_ID`),
  KEY `fk_cars_stores1_idx` (`stores_ID`),
  CONSTRAINT `fk_cars_stores1` FOREIGN KEY (`stores_ID`) REFERENCES `stores` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cars`
--

LOCK TABLES `cars` WRITE;
/*!40000 ALTER TABLE `cars` DISABLE KEYS */;
INSERT INTO `cars` VALUES (9,NULL,'Nissan','Alitma','2012','Like New','99000','Sedan','5/20/2016',80,10,'NULL',9),(10,NULL,'Honda','Civic','2015','New','10000','Sedan','5/20/2016',100,10,'NULL',9),(11,NULL,'BMW','325i','2016','New','5000','Sedan','5/20/2016',150,10,'NULL',9),(12,NULL,'Jeep','Compass','2008','Like New','80000','SUV','5/20/2016',60,10,'NULL',9),(13,NULL,'Ford','Mustang','2016','New','5000','Sport','5/20/2016',150,10,'NULL',9),(14,NULL,'Nissan','Alitma','2012','Like New','99000','Sedan','5/20/2016',80,11,'NULL',9),(15,NULL,'Honda','Civic','2015','New','10000','Sedan','5/20/2016',100,11,'NULL',9),(16,NULL,'BMW','325i','2016','New','5000','Sedan','5/20/2016',150,11,'NULL',9),(17,NULL,'Jeep','Compass','2008','Like New','80000','SUV','5/20/2016',60,12,'NULL',9),(18,NULL,'Ford','Mustang','2016','New','5000','Sport','5/20/2016',150,12,'NULL',9);
/*!40000 ALTER TABLE `cars` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-05-24  2:17:18
