-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema georgescarrentdb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema georgescarrentdb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `georgescarrentdb` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `georgescarrentdb` ;

-- -----------------------------------------------------
-- Table `georgescarrentdb`.`stores`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `georgescarrentdb`.`stores` ;

CREATE TABLE IF NOT EXISTS `georgescarrentdb`.`stores` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Image` MEDIUMBLOB NOT NULL,
  `Name` VARCHAR(255) NOT NULL,
  `FirstStreet` VARCHAR(255) NOT NULL,
  `SecondStreet` VARCHAR(255) NULL DEFAULT NULL,
  `City` VARCHAR(255) NOT NULL,
  `State` VARCHAR(255) NOT NULL,
  `Country` VARCHAR(255) NOT NULL,
  `ZipCode` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
