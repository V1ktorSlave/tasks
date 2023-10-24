-- Создаем базу данных
CREATE DATABASE IF NOT EXISTS mytestdb;
USE mytestdb;

-- Создаем таблицу для хранения пользователей
CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL
);

-- Вставляем некоторые тестовые данные
INSERT INTO users (username, email) VALUES
    ('user1', 'user1@example.com'),
    ('user2', 'user2@example.com'),
    ('user3', 'user3@example.com');
