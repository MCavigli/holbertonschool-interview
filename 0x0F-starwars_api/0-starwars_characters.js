#!/usr/bin/node

const request = require('request');
const url = 'https://swapi.co/api/films/' + process.argv[2];
request.get(url, function (err, res, body) {
  if (err) {
    console.log(err);
    return;
  }
  const characters = JSON.parse(body).characters;
  const nameList = [];
  for (let i = 0; i < characters.length; i++) {
    request.get(characters[i], function (err, res, body) {
      if (err) {
        console.log(err);
        return;
      }
      const name = JSON.parse(body).name;
      nameList.push(name);
    });
  }
  for (let j = 0; j < nameList.length; j++) {
    console.log(nameList[j]);
  }
});
