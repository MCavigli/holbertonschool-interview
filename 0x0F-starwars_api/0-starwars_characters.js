#!/usr/bin/node

const request = require('request');

if (process.argv.length === 3) {
	sw(process.argv[2]);
}
async function sw(id) {
	const url = `https://swapi-api.hbtn.io/api/films/` + id;

	request(url, async function (err, response, body) {
		if (err) {
			console.log(err);
		} else {
			for (const chars in JSON.parse(body).characters) {
				const promise = new Promise(function (res, rej) {
					if (err) {
						console.log(err);
					} else {
						resolve(JSON.parse(chars));
					}
				});
			};
		}
	});
}