import React from 'react'
import vehicles from './api'

export default function Details({getData}) {
    return (
        <>
            <div className="card" style={{marginLeft: '2rem'}}>
                <div className="card-body">
                    <h5 className="card-title">{getData.name}</h5>
                    <p className="card-text">Birthdate: <b>{getData.birthdate}</b></p>
                    <p className="card-text">Nationality: <b>{getData.nationality}</b></p>
                    <p className="card-text">About: <b>{getData.description}</b></p>
                    <p className="card-text">Prominent Work: <b>{getData.prominent_work}</b></p>
                    <img src={getData.image} alt="" height={150} width={250}></img>
                </div>
            </div>
        </>
    )
}
