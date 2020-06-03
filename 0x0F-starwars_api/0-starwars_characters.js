#!/usr/local/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request.get(url, function (err, res, body) {
  if (err) {
    console.log(err);
    return;
  }

  const characters = JSON.parse(body).characters;
  for (let i = 0; i < characters.length; i++) {
    request.get(characters[i], function (err, res, body) {
      if (err) {
        console.log(err);
        return;
      }
      const name = JSON.parse(body).name;
      console.log(name);
    });
  }
});
