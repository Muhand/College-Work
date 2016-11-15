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
CREATE SCHEMA IF NOT EXISTS `georgescarrentdb` DEFAULT CHARACTER SET utf8 ;
USE `georgescarrentdb` ;

-- -----------------------------------------------------
-- Table `georgescarrentdb`.`stores`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `georgescarrentdb`.`stores` ;

CREATE TABLE IF NOT EXISTS `georgescarrentdb`.`stores` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Image` MEDIUMBLOB NULL,
  `Name` VARCHAR(255) NOT NULL,
  `FirstStreet` VARCHAR(255) NOT NULL,
  `SecondStreet` VARCHAR(255) NULL DEFAULT NULL,
  `City` VARCHAR(255) NOT NULL,
  `State` VARCHAR(255) NOT NULL,
  `Country` VARCHAR(255) NOT NULL,
  `ZipCode` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `georgescarrentdb`.`cars`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `georgescarrentdb`.`cars` ;

CREATE TABLE IF NOT EXISTS `georgescarrentdb`.`cars` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `image` MEDIUMBLOB NULL,
  `make` VARCHAR(255) NOT NULL,
  `model` VARCHAR(255) NOT NULL,
  `year` VARCHAR(255) NOT NULL,
  `condition` VARCHAR(255) NOT NULL,
  `mileage` VARCHAR(255) NOT NULL,
  `type` VARCHAR(255) NOT NULL,
  `availability` VARCHAR(10) NOT NULL,
  `priceperday` DOUBLE NOT NULL,
  `description` VARCHAR(400) NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `georgescarrentdb`.`gadgets`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `georgescarrentdb`.`gadgets` ;

CREATE TABLE IF NOT EXISTS `georgescarrentdb`.`gadgets` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `image` MEDIUMBLOB NULL,
  `name` VARCHAR(255) NOT NULL,
  `description` VARCHAR(400) NOT NULL,
  `price` DOUBLE NOT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `georgescarrentdb`.`cars_has_gadgets`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `georgescarrentdb`.`cars_has_gadgets` ;

CREATE TABLE IF NOT EXISTS `georgescarrentdb`.`cars_has_gadgets` (
  `cars_ID` INT NOT NULL,
  `gadgets_ID` INT NOT NULL,
  PRIMARY KEY (`cars_ID`, `gadgets_ID`),
  INDEX `fk_cars_has_gadgets_gadgets1_idx` (`gadgets_ID` ASC),
  INDEX `fk_cars_has_gadgets_cars1_idx` (`cars_ID` ASC),
  CONSTRAINT `fk_cars_has_gadgets_cars1`
    FOREIGN KEY (`cars_ID`)
    REFERENCES `georgescarrentdb`.`cars` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_cars_has_gadgets_gadgets1`
    FOREIGN KEY (`gadgets_ID`)
    REFERENCES `georgescarrentdb`.`gadgets` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `georgescarrentdb`.`stores_has_cars`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `georgescarrentdb`.`stores_has_cars` ;

CREATE TABLE IF NOT EXISTS `georgescarrentdb`.`stores_has_cars` (
  `stores_ID` INT(11) NOT NULL,
  `cars_ID` INT NOT NULL,
  PRIMARY KEY (`stores_ID`, `cars_ID`),
  INDEX `fk_stores_has_cars_cars1_idx` (`cars_ID` ASC),
  INDEX `fk_stores_has_cars_stores1_idx` (`stores_ID` ASC),
  CONSTRAINT `fk_stores_has_cars_stores1`
    FOREIGN KEY (`stores_ID`)
    REFERENCES `georgescarrentdb`.`stores` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_stores_has_cars_cars1`
    FOREIGN KEY (`cars_ID`)
    REFERENCES `georgescarrentdb`.`cars` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `georgescarrentdb`.`stores_has_gadgets`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `georgescarrentdb`.`stores_has_gadgets` ;

CREATE TABLE IF NOT EXISTS `georgescarrentdb`.`stores_has_gadgets` (
  `stores_ID` INT(11) NOT NULL,
  `gadgets_ID` INT NOT NULL,
  PRIMARY KEY (`stores_ID`, `gadgets_ID`),
  INDEX `fk_stores_has_gadgets_gadgets1_idx` (`gadgets_ID` ASC),
  INDEX `fk_stores_has_gadgets_stores1_idx` (`stores_ID` ASC),
  CONSTRAINT `fk_stores_has_gadgets_stores1`
    FOREIGN KEY (`stores_ID`)
    REFERENCES `georgescarrentdb`.`stores` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_stores_has_gadgets_gadgets1`
    FOREIGN KEY (`gadgets_ID`)
    REFERENCES `georgescarrentdb`.`gadgets` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
