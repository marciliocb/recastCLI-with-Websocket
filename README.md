# RecastCLI

A command line tools to build navigation mesh for game, which means you can automatically generate navigation mesh on server or localhost in pipeline via NodeJS. This fork uses an example with Websocket/HTTP integration.

![](https://github.com/Glidias/recastCLI-with-Websocket/raw/nodejs/screenshot.png)

*Above: Usage with Playcanvas. Model used: https://sketchfab.com/models/b874cb19b42741729b950f6afbdf0dea

> Based on [recastnavigation](https://github.com/recastnavigation/recastnavigation) under ZLib license

## Building

```shell
$ node-gyp rebuild
```

## Installing Dependencies
```shell
$ npm install --save websocket
$ npm install --save http
```

## Usage

Run the `start.js` script on node to start your Websocket server. By default, it's set on `ws://localhost:9090`.

```shell
$ node start
```

When your Websocket server receives the appropiate buffer request, (todo: spec this out in documentation), it will generate a file called `navmesh.obj`.

----

## Usage with Playcanvas

With your server running,

Go to Navmesh Generation scene example at 
https://playcanvas.com/editor/scene/645878 and Play it on http protocol (remember to switch play url from `https` to `http` in order to properly access your localhost...):

Project example at:
https://playcanvas.com/project/573035/overview/sketchfab-assets-tests

All script dependencies are required from project. Besides building up a Collision Scene for fast 3D basic collision detection movement and raycasting,  it also has an option to connect to websocket server and help to produce a Navmesh, which will prove useful later on for handling AI movement, point+click movement, automatic spawn location generation, giving commands to AI units to move around, etc.

There are 2 key scripts involved:

- `collision-scene` script on Root entity is used to generate collision scene and/or optionally set up connection to RecastCLI server to build navmesh from Playcanvas' scene graph. Check the box `recastCLIEnable` to auto-connect on post initialization.

- `recastCLI` script on CharacterDemo entity is used as a reference to help automatically generate Recast parameters to send to RecastCLI server, using it's Collision component as a reference. For information on settings in general, refer to: http://digestingduck.blogspot.com/2009/08/recast-settings-uncovered.html . Additionally, I have some zero/negative value attribute resolvers used in the script to derive some calculations dynamically (refer to the code itself to see how it works.)


Once `navmesh.obj` is generated by the server, you can upload it manually to your Playcanvas project to properly integrate it. (to consider: navmesh previewer with server sending back generated navmesh data??)
