/* State declaration */
type state = {
  count: int,
};

/* Action declaration */
type action =
  | Increment
  | Decrement;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (_children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {count: 0},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Increment => ReasonReact.Update({...state, count: state.count + 1})
    | Decrement => ReasonReact.Update({...state, count: state.count - 1})
    },

  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div className="wrapper">
      <button className="increment" onClick=(_event => self.send(Increment))>
        (ReasonReact.string("Increment"))
      </button>
      <button className="decrement" onClick=(_event => self.send(Decrement))>
        (ReasonReact.string("Decrement"))
      </button>
      <div className="info">
        (ReasonReact.string(message))
      </div>
    </div>;
  },
};
