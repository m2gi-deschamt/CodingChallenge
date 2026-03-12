/* CLASS */

class EventType {
  constructor(name, type) {
    this.name = name;
    this.type = type;
  }
}

class User {
  constructor(name) {
    this.name = name;
  }
}

class Subscriber {
  constructor(user, action) {
    this.user = user;
    this.action = action;
  }
}

class nanoBus {
  subscribers = [];
  constructor() {}
  subscribe(eventType, subscriber) {
    this.subscribers.push({ eventType, subscriber });
  }

  unsubscribe(eventType, subscriber) {}

  notify(event) {
    this.subscribers.forEach(({ eventType, subscriber }) => {
      if (event.name == eventType.name) subscriber.action();
    });
  }
}

/* MAIN */

const user1 = new User("Thibaud");
const user2 = new User("Olivier");

const subscriber1 = new Subscriber(user1, () => {
  console.log("Sub 1 call");
});
const subscriber2 = new Subscriber(user2, () => {
  console.log("Sub 2 call");
});

const subscriber3 = new Subscriber(user1, () => {
  console.log("Sub 3 call");
});

const turboEvent = new EventType("TurboEvent", "alert");
const greenEvent = new EventType("Green event", "fun");

const bus = new nanoBus("Turbo", 32);
bus.subscribe(turboEvent, subscriber1);
bus.subscribe(greenEvent, subscriber2);
bus.subscribe(greenEvent, subscriber3);
bus.notify(turboEvent);
setTimeout(() => {
  bus.notify(greenEvent);
}, 5000);
