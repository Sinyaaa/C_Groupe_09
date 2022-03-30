-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : sam. 26 mars 2022 à 12:17
-- Version du serveur : 10.4.20-MariaDB
-- Version de PHP : 8.0.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `c_groupe_09`
--

-- --------------------------------------------------------

--
-- Structure de la table `marques`
--

CREATE TABLE `marques` (
  `id_marques` int(11) NOT NULL,
  `name_marques` varchar(50) DEFAULT NULL,
  `niceName_marques` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `modeles`
--

CREATE TABLE `modeles` (
  `id_modeles` int(11) NOT NULL,
  `name_modeles` varchar(50) DEFAULT NULL,
  `niceName_modeles` varchar(50) DEFAULT NULL,
  `id_marques` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `versions`
--

CREATE TABLE `versions` (
  `id_versions` int(11) NOT NULL,
  `name_versions` varchar(50) DEFAULT NULL,
  `power_versions` varchar(50) DEFAULT NULL,
  `id_modeles` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `marques`
--
ALTER TABLE `marques`
  ADD PRIMARY KEY (`id_marques`);

--
-- Index pour la table `modeles`
--
ALTER TABLE `modeles`
  ADD PRIMARY KEY (`id_modeles`),
  ADD KEY `makeId_modeles` (`id_marques`);

--
-- Index pour la table `versions`
--
ALTER TABLE `versions`
  ADD PRIMARY KEY (`id_versions`),
  ADD KEY `modelNiceName_versions` (`id_modeles`);

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `modeles`
--
ALTER TABLE `modeles`
  ADD CONSTRAINT `makeId_modeles` FOREIGN KEY (`id_marques`) REFERENCES `marques` (`id_marques`);

--
-- Contraintes pour la table `versions`
--
ALTER TABLE `versions`
  ADD CONSTRAINT `modelNiceName_versions` FOREIGN KEY (`id_modeles`) REFERENCES `modeles` (`id_modeles`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
