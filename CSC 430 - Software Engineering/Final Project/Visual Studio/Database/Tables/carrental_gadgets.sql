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
-- Table structure for table `gadgets`
--

DROP TABLE IF EXISTS `gadgets`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `gadgets` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `image` mediumblob,
  `name` varchar(255) NOT NULL,
  `description` varchar(400) NOT NULL,
  `price` double NOT NULL,
  `cars_ID` int(11) NOT NULL,
  `cars_stores_ID` int(11) NOT NULL,
  `quantity_available` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`cars_ID`,`cars_stores_ID`),
  KEY `fk_gadgets_cars1_idx` (`cars_ID`,`cars_stores_ID`),
  CONSTRAINT `fk_gadgets_cars1` FOREIGN KEY (`cars_ID`, `cars_stores_ID`) REFERENCES `cars` (`ID`, `stores_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gadgets`
--

LOCK TABLES `gadgets` WRITE;
/*!40000 ALTER TABLE `gadgets` DISABLE KEYS */;
INSERT INTO `gadgets` VALUES (5,NULL,'Baby Seat','This is a great and safe seat for your kid(s).',50,9,10,10),(6,NULL,'GPS','Get a gps and find your way.',80,9,10,3),(6,NULL,'GPS','Get a gps and find your way.',80,10,10,3),(6,NULL,'GPS','Get a gps and find your way.',80,11,10,3),(6,NULL,'GPS','Get a gps and find your way.',80,12,10,3),(6,NULL,'GPS','Get a gps and find your way.',80,13,10,3),(7,NULL,'AUX Cable','Listen to your music with AUX cable.',5,9,10,15),(8,NULL,'Baby Seat','This is a great and safe seat for your kid(s).',50,10,10,10),(9,NULL,'Baby Seat','This is a great and safe seat for your kid(s).',50,11,10,10),(10,NULL,'Baby Seat','This is a great and safe seat for your kid(s).',50,12,10,10),(11,NULL,'Baby Seat','This is a great and safe seat for your kid(s).',50,13,10,10);
/*!40000 ALTER TABLE `gadgets` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-05-24  2:17:17
