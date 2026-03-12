# Turbo bus

I implemented a version of the "observer" design pattern for a simple use case.

## Specifications

I want to have a bus where people subscribe to events and execute simple but personalized commands. People decide what to do when something happens on the bus.

### Bus

#### Parameters

- Hashmap, {subscriber, eventType}

#### Functions

- subscribe(subscriber, eventType)
- unsubscribe(subscriber, eventType)
- notify(eventType)

## Applicability

Use the Observer pattern when changes to the state of one object may require changing other objects, and the actual set of objects is unknown beforehand or changes dynamically.

## resources

https://refactoring.guru/design-patterns/observer
