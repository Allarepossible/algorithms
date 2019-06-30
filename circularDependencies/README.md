На вход программы подается массив из зависимостей, на выходе нужно сказать есть ли среди зависимостей зацикленность или нет.

Примеры:

1. Зациленности нет:
```
const Dependencies = {
    'index.js': ['foo.js', 'bar.js', 'firts.js', 'style.css'],
    'foo.js': ['bar.js'],
    'bar.js': [],
    'first.js': ['second.js'],
    'second.js': ['third.js'],
}
```
2. Зацикленность есть:
```
const Dependencies = {
    'index.js': ['foo.js', 'bar.js', 'firts.js', 'style.css'],
    'foo.js': ['bar.js'],
    'bar.js': ['foo.js'],
    'first.js': ['second.js'],
    'second.js': ['third.js'], 
}
```
```
const Dependencies = {
    'index.js': ['foo.js', 'bar.js', 'firts.js', 'style.css'],
    'foo.js': ['bar.js'],
    'bar.js': ['first.js'],
    'first.js': ['second.js'],
    'second.js': ['foo.js'],
}
```
Задачу можно решить несколькими способами. Начну с обхода дерева в глубину с помощью рекурсии
