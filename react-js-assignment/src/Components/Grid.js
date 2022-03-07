import React, { useState } from 'react'
import scientists from './api'
import Details from './Details'

export default function Grid() {
    const [data, setdata] = useState('')
    const [toggle, settoggle] = useState(0)

    const clickHandler = (data) => {
        setdata(data);
        settoggle(1);
    }
    const backBtn = () => {
        settoggle(0);
    }

    if (toggle == 0) {
        return (
            <>
                <div className="container" style={{marginBottom: '3rem'}}>
                    <div className="row" style={{gap:'5rem'}}>
                        <div className="col">
                            <h1>{scientists[0].name}</h1>
                            <p>{scientists[0].description}</p>
                            <img src={scientists[0].image} alt="" height={150} width={250} style={{marginBlock: '1rem'}}></img>
                            <br />
                            <button onClick={() => clickHandler(scientists[0])}>View Details</button>
                        </div>
                        <div className="col">
                            <h1>{scientists[1].name}</h1>
                            <p>{scientists[1].description}</p>
                            <img src={scientists[1].image} alt="" height={150} width={250} style={{marginBlock: '1rem'}}></img>
                            <br />
                            <button onClick={() => clickHandler(    scientists[1])}>View Details</button>
                        </div>
                        <div className="col">
                            <h1>{scientists[2].name}</h1>
                            <p>{scientists[2].description}</p>
                            <img src={scientists[2].image} alt="" height={150} width={250} style={{marginBlock: '1rem'}}></img>
                            <br />
                            <button onClick={() => clickHandler(scientists[2])}>View Details</button>
                        </div>
                    </div>
                </div>
            </>

        )
    }
    else {
        return (
            <>
            <button onClick={() => backBtn()} style={{marginLeft:'2rem'}}>Go back</button>
            <Details getData={data}></Details>
                
            </>
        )
    }
}
